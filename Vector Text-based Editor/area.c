

#include <stdio.h>
#include "area.h"

Area* create_area(unsigned int width, unsigned int height){
    Area* zone = (Area * )malloc(sizeof(Area));
    zone->mat = (BOOL**) malloc(sizeof(BOOL*)*height);
    for (unsigned int i = 0; i < height; i++) {
        zone->mat[i] = (BOOL *) calloc(width, sizeof(BOOL)*width);
    }
    zone->nb_shape = 0;
    zone->width = width;
    zone->height = height;
    return zone;
}

void add_shape_to_area(Area* area, Shape* shape){
    area -> shapes[area->nb_shape] = shape;
    area->nb_shape ++;
}

void clear_area(Area* area){
    for (int x = 0; x <= area->width;x++) {
        for (int y = 0;y <= area->height;y++){
            area -> mat[x][y] = 0;
        }
    }
};

void erase_area(Area* area){
    for (int x = 0; x < area->width;x++) {
        for (int y = 0;y < area->height;y++){
            area -> mat = NULL;
            free(area -> shapes[x][y].ptrShape);
        }
    }
}

void delete_area(Area* area){
    area = NULL;
    free(area);
}

void draw_area(Area* area){
    Pixel** pixels = NULL;
    int nb_pixels = 0;

    for (int i = 0; i < area->nb_shape; i++) {
        create_shape_to_pixel(area->shapes[i], &nb_pixels, &pixels);
        for (int j = 0; j < nb_pixels; j++) {
            int x = pixels[j]->px;
            int y = pixels[j]->py;
            if (x >= 0 && x < area->height && y >= 0 && y < area->width) {
                area->mat[x][y] = 1;
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

void create_shape_to_pixel(Shape* shape, int* nb_pixels, Pixel*** pixels){
    *pixels = (Pixel**) malloc( (* nb_pixels) * sizeof(Pixel*) );

    if (shape->ptrShape != NULL) {
        if (shape->shape_type == POINT) {
            pixel_point(shape, pixels, nb_pixels);
        }
        else if (shape->shape_type == LINE) {
            pixel_line(shape->ptrShape, pixels, nb_pixels);
        }
        else if (shape->shape_type == SQUARE){
            pixel_square(shape->ptrShape, pixels, nb_pixels);
        }
        else if (shape->shape_type == RECTANGLE) {
            pixel_rectangle(shape->ptrShape, pixels, nb_pixels);
        }
        else if (shape->shape_type == CIRCLE) {
            pixel_circle(shape->ptrShape, pixels, nb_pixels);
        }
        else if (shape->shape_type == POLYGON) {
            pixel_polygon(shape->ptrShape, pixels, nb_pixels);
        }
        else {
            printf("Unknown: %u\n", shape->shape_type);
        }
    }
}
