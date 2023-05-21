#include <malloc.h>
#include "stdio.h"
#include "Point.h"



Point *create_point(int px,int py){
    Point *p = malloc(sizeof(Point));;
    p->pos_x = px;
    p->pos_y = py;
    return p;
}


void delete_point(Point * point){
    free(point);
    point = NULL;
}

void print_point(Point * p){
    printf("POINT[%d,%d]",p->pos_x,p->pos_y);
}
