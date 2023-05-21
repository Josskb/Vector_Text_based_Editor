#include <stdlib.h>
#include <stdio.h>
#include "Polygon.h"


Polygon *create_polygon(int n){
    Polygon* poly = malloc(sizeof(Polygon));
    int X,Y;
    printf("Enter the 1st coordinates X1 Y1 :");
    scanf(" %d %d",&X,&Y);
    Point* points1 = create_point(X,Y);
    poly->points = malloc(n*sizeof(Point*));
    poly->n = n;
    poly->points[0] = points1;
    for (int i = 1; i<n-1;i++){
        printf("Enter the %d coordinates X%d Y%d :",i+1,i+1,i+1);
        scanf(" %d %d",&X,&Y);
        poly->points[i] = create_point(X,Y);
    }
    printf("Enter the last coordinates X%d Y%d:",n,n);
    scanf(" %d %d",&X,&Y);
    Point* points_f = create_point(X,Y);
    poly->points[n] = points_f;
    if (points1->pos_x == points_f->pos_x && points1->pos_y == points_f->pos_y) {
        printf("It works\n");
        return poly;
    }
    else return 0;
}

void delete_polygon(Polygon * polygon){
    free(polygon);
    polygon = NULL;
}
void print_polygon(Polygon* polygon){
    printf("Polygon: n=%d, points=[", polygon->n);
    for (int i = 0; i < (polygon->n)-1; i++){
        printf("(%d,%d)", polygon->points[i]->pos_x, polygon->points[i]->pos_y);
        if (i != polygon->n-1){
            printf(", ");
        }
    }
    printf("(%d,%d)",polygon->points[polygon->n]->pos_x,polygon->points[polygon->n]->pos_y);
    printf("]");
}
