#include <stdlib.h>
#include <stdio.h>
#include "Circle.h"

Circle *create_circle(Point * center, int radius){
    Circle* circle = NULL;
    circle->p = center;
    circle->radius = radius;
    return circle;
}

void delete_circle(Circle * circle){
    free(circle);
    circle = NULL;
}

void print_circle(Circle * circle){
    printf("[%d,%d,%d]",circle->p->pos_x,circle->p->pos_y,circle->radius);
}

