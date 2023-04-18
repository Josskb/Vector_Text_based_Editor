#include <malloc.h>
#include "Square.h"
#include "stdio.h"

Square *create_square(Point * point, int length) {
    Square* Square = NULL;
    Square->p = point;
    Square->Len = length;
    return Square;
}

void delete_square(Square * square){
    free(square);
    square = NULL;
}

void print_square(Square * square){
    printf("[(%d,%d),(%d,%d),(%d,%d),(%d,%d)]",square->p->pos_x,square->p->pos_y,square->p->pos_x,(square->p->pos_y)+square->Len,(square->p->pos_x)+square->Len,square->p->pos_y,(square->p->pos_x)+square->Len,(square->p->pos_y)+square->Len);
}
