#include <stdio.h>
#include "Rectangle.h"
#include "stdlib.h"

Rectangle *create_rectangle(Point * point, int width, int height){
    Rectangle* Rectangle = NULL;
    Rectangle->p = point;
    Rectangle->len = height;
    Rectangle->wid = width;
    return Rectangle;
};

void delete_rectangle(Rectangle * rectangle){
    free(rectangle);
    rectangle = NULL;
}

void print_rectangle(Rectangle * rectangle){
    printf("[(%d,%d),(%d,%d),(%d,%d),(%d,%d)]",rectangle->p->pos_x,rectangle->p->pos_y,rectangle->p->pos_x,(rectangle->p->pos_y)+rectangle->len,(rectangle->p->pos_x)+rectangle->wid,rectangle->p->pos_y,(rectangle->p->pos_x)+rectangle->wid,(rectangle->p->pos_y)+rectangle->len);
}