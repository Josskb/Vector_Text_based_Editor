#include "..\Point.h"

#ifndef VECTOR_TEXT_BASED_EDITOR_CIRCLE_H
#define VECTOR_TEXT_BASED_EDITOR_CIRCLE_H

typedef struct circle{
    Point * p;
    int radius;
}Circle;

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);



#endif //VECTOR_TEXT_BASED_EDITOR_CIRCLE_H
