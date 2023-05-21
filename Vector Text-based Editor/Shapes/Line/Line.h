
#ifndef VECTOR_TEXT_BASED_EDITOR_LINE_H
#define VECTOR_TEXT_BASED_EDITOR_LINE_H

#include "..\Point.h"

typedef struct line {
    Point *p1;
    Point *p2;
}Line;

Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);


#endif //VECTOR_TEXT_BASED_EDITOR_LINE_H
