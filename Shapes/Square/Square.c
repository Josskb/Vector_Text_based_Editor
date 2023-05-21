#include <malloc.h>
#include "Square.h"
#include "stdio.h"

Square *create_square(Point * point, int length) {
    Square* square = (Square *) malloc(sizeof(Square));;
    square->p = create_point(point->pos_x,point->pos_y);
    square->Len = length;
    return square;
}

void delete_square(Square * square){
    free(square);
    square = NULL;
}

void print_square(Square * square){
    printf("SQUARE[(%d,%d),(%d,%d),(%d,%d),(%d,%d)]",square->p->pos_x,square->p->pos_y,square->p->pos_x,(square->p->pos_y)+square->Len,(square->p->pos_x)+square->Len,square->p->pos_y,(square->p->pos_x)+square->Len,(square->p->pos_y)+square->Len);
}
