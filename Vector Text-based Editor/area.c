

#include <stdio.h>
#include "area.h"

Area* create_area(unsigned int width, unsigned int height){
    unsigned int taille = width * height;
    Area* zone = (Area * )calloc(taille,sizeof(Area));
    zone->width = width;
    zone->height = height;
    return zone;
}

void add_shape_to_area(Area* area, Shape* shape){
    area -> shapes[area->nb_shape] = shape;
    area->nb_shape ++;
}

void clear_area(Area* area){
    for (int x = 0; x < area->width;x++) {
        for (int y = 0;y < area->height;y++){
            area -> mat = 0;
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

void draw_area(Area* area) {
    for (int i = 0; i < area->nb_shape; i++) {
        int nbr_pix = 0;
        int *nb_pixels = &nbr_pix;
        Pixel** pixels = NULL;
        create_shape_to_pixel(area->shapes[i], nb_pixels);
        for (int j = 0; j < *nb_pixels; j++) {
            int x = pixels[j]->px;
            int y = pixels[j]->py;
            if (x >= 0 && x < area->height && y >= 0 && y < area->width) {
                area->mat[x][y] = 1;
                free(pixels[j]);
                pixels[j] = NULL;
            }
        }
        free(pixels);
    }
}


void print_area(Area* area){
    for (int x = 0; x < area->width;x++) {
        for (int y = 0;y < area->height;y++){
            if (area->mat[x][y] == 0){
                printf(".");
            }
            else printf("#");
        }
        printf("\n");
    }
}

void create_shape_to_pixel(Shape* shape, int* nb_pixels)
{
    Pixel*** pixel = (Pixel***) malloc(sizeof (Pixel**));

    if (shape->ptrShape != NULL) {
        if (shape->shape_type == POINT) {
            pixel_point(shape, pixel, nb_pixels);
        }
        else if (shape->shape_type == LINE) {
            pixel_line(shape->ptrShape, pixel, nb_pixels);
        }
        else if (shape->shape_type == SQUARE){
            pixel_square(shape->ptrShape, pixel, nb_pixels);
        }
        else if (shape->shape_type == RECTANGLE) {
            pixel_rectangle(shape->ptrShape, pixel, nb_pixels);
        }
        else if (shape->shape_type == CIRCLE) {
            pixel_circle(shape->ptrShape, pixel, nb_pixels);
        }
        else if (shape->shape_type == POLYGON) {
            pixel_polygon(shape->ptrShape, pixel, nb_pixels);
        }
        else {
            printf("Unknown: %u\n", shape->shape_type);
        }
    }
}


