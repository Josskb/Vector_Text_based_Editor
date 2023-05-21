#include "Line.h"
#include <malloc.h>
#include "stdio.h"

Line *create_line(Point * p1, Point * p2){
    Line* L = malloc(sizeof(Line));
    L->p1 = create_point(p1->pos_x,p1->pos_y);
    L->p2 = create_point(p2->pos_x,p2->pos_y);
    return L;
}

void delete_line(Line * line){
    free(line);
    line = NULL;
}

void print_line(Line * line){
    printf("LINE[%d, %d, %d, %d]",line->p1->pos_x,line->p1->pos_y,line->p2->pos_x,line->p2->pos_y) ;
}
