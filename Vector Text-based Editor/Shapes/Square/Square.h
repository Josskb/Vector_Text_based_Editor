//
// Created by ratch on 18/04/2023.
//

#include "..\Point.h"

#ifndef VECTOR_TEXT_BASED_EDITOR_SQUARE_H
#define VECTOR_TEXT_BASED_EDITOR_SQUARE_H

typedef struct square{
    Point *p;
    int Len;
}Square;

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);


#endif //VECTOR_TEXT_BASED_EDITOR_SQUARE_H
