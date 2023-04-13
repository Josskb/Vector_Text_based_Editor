//
// Created by ratch on 22/03/2023.
//

typedef struct{
    int pos_x;
    int pos_y;
}Point;

Point *create_point(int px,int py);

void delete_point(Point * point);

void print_point(Point * p);
