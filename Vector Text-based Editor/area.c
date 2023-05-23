

#include <stdio.h>
#include <string.h>
#include "area.h"

Area* create_area(unsigned int width, unsigned int height){
    Area* zone = (Area * )malloc(sizeof(Area));
    zone->mat = (BOOL**) malloc(sizeof(BOOL*)*height);
    for (unsigned int i = 0; i < height; i++) {
        zone->mat[i] = (BOOL *) calloc(width, sizeof(BOOL));
    }
    zone->nb_shape = 0;
    zone->width = width;
    zone->height = height;
    clear_area(zone);
    return zone;
}

// Function to add a shape to the area
void add_shape_to_area(Area* zone, Shape* shape) {
    if (zone->nb_shape >= SHAPE_MAX) {
        // Handle maximum number of shapes reached
        // (according to your requirements)
        return;
    }
    zone->shapes[zone->nb_shape] = shape;
    zone->nb_shape++;
}


//clear la zone
void clear_area(Area* area){
    for (int x = 0; x < area->width;x++) {
        for (int y = 0;y < area->height;y++){
            area -> mat[x][y] = 0;
        }
    }
};
void erase_area(Area* area) {
    for (int i = 0; i<area->nb_shape; i++) {
        delete_shape(area->shapes[i]);
    }
    area->nb_shape = 0;
    clear_area(area);
}

void delete_area(Area* area){
    if (area != NULL) {
        for (int i = 0; i < area->nb_shape; i++) {
            if (area->shapes[i] != NULL) {
                delete_shape(area->shapes[i]);
                area->shapes[i] = NULL;
            }
        }
        free(area->shapes);

        for (unsigned int i = 0; i < area->height; i++) {
            free(area->mat[i]);
        }
        free(area->mat);
        area->mat = NULL;

        free(area);
    }
}

void draw_area(Area* area) {
    clear_area(area);
    int nb_pixels;
    Pixel **pixels;
    for (int i = 0; i<area->nb_shape; i++) {
        pixels = create_shape_to_pixel(area->shapes[i], &nb_pixels);
        for (int j = 0; j<nb_pixels; j++) {
            if (area->height > pixels[j]->py && pixels[j]->py >= 0 && area->width > pixels[j]->px && area->width >= 0) {
                area->mat[pixels[j]->py][pixels[j]->px] = 1;
            }
        }
        delete_pixel_shape(pixels, nb_pixels);
    }
}


void print_area(Area* area){
    for (int y = 0; y < area->height; y++) {
        for (int x = 0; x < area->width; x++){
            if (area->mat[x][y] == 0){
                printf(" .");
            }
            else {
                printf(" #");
            }
        }
        printf("\n");
    }
}

Pixel** create_shape_to_pixel(Shape* shape, int *nb_pixels) {
    switch (shape->shape_type) {
        case POINT:
            return pixel_point(shape, nb_pixels);
            break;
        case LINE:
            return pixel_line(shape,nb_pixels);
            break;
        case RECTANGLE:
            return pixel_rectangle(shape,nb_pixels);
            break;
        case SQUARE:
            return pixel_square(shape,nb_pixels);
            break;
        case CIRCLE:
            return pixel_circle(shape,nb_pixels);
            break;
        case POLYGON: {
            return pixel_polygon(shape,nb_pixels);
            break;
        }
        default:
            return NULL;
            break;
    }
}
