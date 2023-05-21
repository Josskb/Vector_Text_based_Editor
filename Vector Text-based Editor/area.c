

#include <stdio.h>
#include "area.h"

Area* create_area(unsigned int width, unsigned int height){
    Area * zone = (Area * )malloc(sizeof(Area));
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

/*void draw_area(Area* area){
    for(int x = 0; x< area->nb_shape;x++){
        create_shape_to_pixel(area -> shapes[x]);
    }
}*/

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


