
#include "..\Point.h"

#ifndef VECTOR_TEXT_BASED_EDITOR_POLYGON_H
#define VECTOR_TEXT_BASED_EDITOR_POLYGON_H

typedef struct polygon{
    int n;
    Point** points;
}Polygon;

Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);


#endif //VECTOR_TEXT_BASED_EDITOR_POLYGON_H
