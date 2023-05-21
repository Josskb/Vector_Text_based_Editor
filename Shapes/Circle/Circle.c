#include <stdlib.h>
#include <stdio.h>
#include "Circle.h"

Circle *create_circle(Point * center, int radius){
    Circle* circle = malloc(sizeof(Circle));
    circle->p = create_point(center->pos_x,center->pos_y);
    circle->radius = radius;
    return circle;
}

void delete_circle(Circle * circle){
    free(circle);
    circle = NULL;
}

void print_circle(Circle * circle){
    printf("CIRCLE[%d,%d,%d]",circle->p->pos_x,circle->p->pos_y,circle->radius);
}

