#include <malloc.h>
#include <stdio.h>
#include "Shape.h"

int id = 0;

Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = get_next_id();
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2) {
    Shape *shp = create_empty_shape(LINE);
    Point *p1 = create_point(px1, py1);
    Point *p2 = create_point(px2, py2);
    Line *l = create_line(p1,p2);
    shp->ptrShape = l;
    return shp;
}

Shape *create_square_shape(int px, int py, int length) {
    Shape *shp = create_empty_shape(SQUARE);
    Point *p = create_point(px, py);
    Square* s = create_square(p, length);
    shp->ptrShape = s;
    return shp;
}

Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p = create_point(px, py);
    Rectangle* r = create_rectangle(p, width, height);
    shp->ptrShape = r;
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius){
    Shape *shp = create_empty_shape(CIRCLE);
    Point *p = create_point(px, py);
    Circle* c = create_circle(p, radius);
    shp->ptrShape = c;
    return shp;
}

Shape *create_polygon_shape(int n){
    Shape *shp = create_empty_shape(POLYGON);
    if (n%2==0){
        Polygon *poly = create_polygon(n);
        shp->ptrShape = poly;
        return shp;
    }
    else return 0;
}

void print_shape(Shape *shape){
    printf("ID : %d, ",shape->id);
    if (shape->shape_type == POINT)
    {
        print_point(shape->ptrShape);
    }
    else if (shape->shape_type == LINE)
    {
        print_line(shape->ptrShape);
    }
    else if (shape->shape_type == CIRCLE)
    {
        print_circle(shape->ptrShape);
    }
    else if (shape->shape_type == RECTANGLE)
    {
        print_rectangle(shape->ptrShape);
    }
    else if (shape->shape_type == SQUARE)
    {
        print_square(shape->ptrShape);
    }
    else if (shape->shape_type == POLYGON)
    {
        print_polygon(shape->ptrShape);
    }
    printf("\n");

}

int get_next_id(){
    id ++;
    return id;
}







