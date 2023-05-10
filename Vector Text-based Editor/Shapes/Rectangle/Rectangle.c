#include <stdio.h>
#include "Rectangle.h"
#include "stdlib.h"

Rectangle *create_rectangle(Point * point, int width, int height){
    Rectangle* rectangle = malloc(sizeof(Rectangle));
    rectangle->p = create_point(point->pos_x,point->pos_y);
    rectangle->len = height;
    rectangle->wid = width;
    return rectangle;
};

void delete_rectangle(Rectangle * rectangle){
    free(rectangle);
    rectangle = NULL;
}

void print_rectangle(Rectangle * rectangle){
    printf("RECTANGLE[(%d,%d),(%d,%d),(%d,%d),(%d,%d)]",rectangle->p->pos_x,rectangle->p->pos_y,rectangle->p->pos_x,(rectangle->p->pos_y)+rectangle->len,(rectangle->p->pos_x)+rectangle->wid,rectangle->p->pos_y,(rectangle->p->pos_x)+rectangle->wid,(rectangle->p->pos_y)+rectangle->len);
}