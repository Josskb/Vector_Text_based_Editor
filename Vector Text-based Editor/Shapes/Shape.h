
#ifndef VECTOR_TEXT_BASED_EDITOR_SHAPE_H
#define VECTOR_TEXT_BASED_EDITOR_SHAPE_H

#include "Point.h"
#include "Square\Square.h"
#include "Rectangle\Rectangle.h"
#include "Polygon\Polygon.h"
#include "Line\Line.h"
#include "Circle\Circle.h"

typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;
typedef struct {
    int id; // unique identifier of the shape
    SHAPE_TYPE shape_type; // type of the shape pointed
    void *ptrShape; // pointer to any shape
}Shape;

Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radius);
Shape *create_polygon_shape(int n);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);
int get_next_id();

#endif //VECTOR_TEXT_BASED_EDITOR_SHAPE_H
