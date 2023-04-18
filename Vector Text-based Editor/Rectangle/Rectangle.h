#include "C:\Users\ratch\CLionProjects\Vector Text-based Editor\Shapes\Point.h"

#ifndef VECTOR_TEXT_BASED_EDITOR_RECTANGLE_H
#define VECTOR_TEXT_BASED_EDITOR_RECTANGLE_H

typedef struct rectangle{
    Point* p;
    int len;
    int wid;
}Rectangle;

Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);



#endif //VECTOR_TEXT_BASED_EDITOR_RECTANGLE_H
