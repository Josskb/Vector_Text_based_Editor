#include <malloc.h>
#include <stdio.h>
#include "Shape.h"

int id = 0;

//crée une forme vide
Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = get_next_id();
    shp->shape_type = shape_type;
    return shp;
}

//crée une forme point
Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

//crée une forme ligne
Shape *create_line_shape(int px1, int py1, int px2, int py2) {
    Shape *shp = create_empty_shape(LINE);
    Point *p1 = create_point(px1, py1);
    Point *p2 = create_point(px2, py2);
    Line *l = create_line(p1,p2);
    shp->ptrShape = l;
    return shp;
}

//crée une forme carrée
Shape *create_square_shape(int px, int py, int length) {
    Shape *shp = create_empty_shape(SQUARE);
    Point *p = create_point(px, py);
    Square* s = create_square(p, length);
    shp->ptrShape = s;
    return shp;
}

//crée une forme rectangle
Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p = create_point(px, py);
    Rectangle* r = create_rectangle(p, width, height);
    shp->ptrShape = r;
    return shp;
}

//crée une forme cercle
Shape *create_circle_shape(int px, int py, int radius){
    Shape *shp = create_empty_shape(CIRCLE);
    Point *p = create_point(px, py);
    Circle* c = create_circle(p, radius);
    shp->ptrShape = c;
    return shp;
}

//crée une forme polygone
Shape *create_polygon_shape(int list_point[], int n){
    if (n % 2 != 0) {
        printf("Error: The number of points must be even.\n");
        return NULL;
    }
    Shape *shp = create_empty_shape(POLYGON);
    Polygon *poly = create_polygon(n/2);
    for (int i = 0; i < n; i += 2) {
        Point *p = create_point(list_point[i], list_point[i+1]);
        poly->points[i/2] = p;
    }
    shp->ptrShape = poly;
    return shp;
}

//fonctions qui regroupe toutes les fonctions print de formes
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

//fonctions qui regroupe toutes les fonctions delete de formes
void delete_shape(Shape * shape){

    if (shape->shape_type == POINT)
    {

        delete_point(shape->ptrShape);
        id--;
    }
    else if (shape->shape_type == LINE)
    {

        delete_line(shape->ptrShape);
        id--;
    }
    else if (shape->shape_type == CIRCLE)
    {

        delete_circle(shape->ptrShape);
        id--;
    }
    else if (shape->shape_type == RECTANGLE)
    {

        delete_rectangle(shape->ptrShape);
        id--;
    }
    else if (shape->shape_type == SQUARE)
    {

        delete_square(shape->ptrShape);
        id--;
    }
    else if (shape->shape_type == POLYGON)
    {

        delete_polygon(shape->ptrShape);
        id--;
    }

}

//récupére l'ID d'après
int get_next_id(){
    id ++;
    return id;
}








