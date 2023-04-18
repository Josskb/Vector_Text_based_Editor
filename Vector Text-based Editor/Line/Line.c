#include "Line.h"
#include <malloc.h>
#include "stdio.h"

Line *create_line(Point * p1, Point * p2){
    Line* L = NULL;
    L->p1 = p1;
    L->p2 = p2;
    return L;
}

void delete_line(Line * line){
    free(line);
    line = NULL;
}

void print_line(Line * line){
    printf("[%d, %d, %d, %d]",line->p1->pos_x,line->p1->pos_y,line->p2->pos_x,line->p2->pos_y) ;
}
