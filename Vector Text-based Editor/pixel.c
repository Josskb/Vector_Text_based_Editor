//
// Created by ratch on 17/05/2023.
//

#include <malloc.h>
#include <minmax.h>
#include "pixel.h"

Pixel* create_pixel(int px, int py){
    Pixel* pixel = (Pixel *) malloc(sizeof(Pixel));
    pixel->px = px;
    pixel->py = py;
    return pixel;
}

void delete_pixel(Pixel* pixel){
    pixel = NULL;
    free(pixel);
}

void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels)
{
    Point* pt = (Point*) shape->ptrShape;
    *pixel_tab = (Pixel**) malloc (sizeof (Pixel*));
    *pixel_tab[0] = create_pixel(pt->pos_x, pt->pos_y);
    *nb_pixels = 1;
}

void pixel_line(Shape* shape, Pixel*** pixel, int* nb_pixels) {
    Line *l = (Line *) shape->ptrShape;
    Point *p1 = l->p1;
    Point *p2 = l->p2;
    int p1_x = p1->pos_x;
    int p1_y = p1->pos_y;
    int p2_x = p2->pos_x;
    int p2_y = p2->pos_y;

    int dx = p2_x - p1_x;
    int dy = p2_y - p1_y;

    int dmin = min(dx, abs(dy));
    int dmax = max(dx, abs(dy));

    int nb_segs;
    nb_segs = dmin + 1;
    int taille_base_segs = (dmax + 1) / (dmin + 1);
    int segments[nb_segs];
    for (int i = 0; i < nb_segs; i++) {
        segments[i] = taille_base_segs;
    }
    int restants;
    restants = (dmax + 1) % (dmin + 1);

    int *cumuls = (int *) malloc(nb_segs * sizeof(int));
    cumuls[0] = 0;
    for (int i = 1; i < nb_segs; i++) {
        cumuls[i] = ((i + 1) * restants) % (dmin + 1) < (i * restants) % (dmin + 1);
        segments[i] = segments[i] + cumuls[i];
    }
    int pixel_index = 1;
    for (int i = 0; i < nb_segs; i++) {
        for (int j = 0; j < segments[i]; j++) {
            if (dx >= 0) {
                if (dy > dx) {
                    *pixel[pixel_index] = create_pixel(p1_x, p1_y);
                    dx--;
                    p1_y++;
                } else {

                    *pixel[pixel_index] = create_pixel(dy, abs(dx));
                    dy--;
                    p1_x--;
                }
            }
            else {
                if (dy > abs(dx)) {

                    *pixel[pixel_index] = create_pixel(dx, dy);
                    dy++;
                    p1_x--;
                }
                else {
                    *pixel[pixel_index] = create_pixel(dx, dy);
                    dx--;
                    p1_y++;
                }
            }
            pixel_index++;
        }
    }
}

void pixel_circle(Shape *shape, Pixel*** pixel, int *nb_pixels) {
    Circle* circle = (Circle *) shape ->ptrShape;
    int x = 0;
    int y = circle->radius;
    int d = circle->radius - 1;

    while (y >= x) {
        // Add the point for the first octant
        Pixel* px = create_pixel(circle->p->pos_x + x, circle->p->pos_y + y);
        (*pixel)[(*nb_pixels)++] = px;

        // Add the point for the octant opposite
        px = create_pixel(circle->p->pos_x + y, circle->p->pos_y + x);
        (*pixel)[(*nb_pixels)++] = px;

        // Add the same for the remaining six octants
        // ...

        if (d >= 2 * x) {
            d -= 2 * x + 1;
            x++;
        }
        else if (d < 2 * (circle->radius - y)) {
            d += 2 * y - 1;
            y--;
        }
        else {
            d += 2 * (y - x - 1);
            y--;
            x++;
        }
    }
}

void pixel_square(Shape* shape, Pixel*** pixel_tab, int* nb_pixels){
    Square* square = (Square *) shape->ptrShape;
    int px = square->p->pos_x;
    int py = square->p->pos_y;
    int length = square->Len;

    pixel_line(create_line_shape(px, py, px, py + length), pixel_tab, nb_pixels);
    pixel_line(create_line_shape(px, py, px + length, py), pixel_tab, nb_pixels);
    pixel_line(create_line_shape(px + length, py, px + length, py + length), pixel_tab, nb_pixels);
    pixel_line(create_line_shape(px, py + length, px + length, py + length), pixel_tab, nb_pixels);
}




void pixel_rectangle(Shape* shape, Pixel*** pixel_tab, int* nb_pixels){
    Rectangle * rectangle = (Rectangle*) shape ->ptrShape;
    int px = rectangle->p->pos_x;
    int py = rectangle->p->pos_y;
    int width = rectangle->wid;
    int height = rectangle->len;
    pixel_line(create_rectangle_shape(px, py, px + width, py), pixel_tab, nb_pixels);
    pixel_line(create_rectangle_shape(px + width, py, px + width, py + height), pixel_tab, nb_pixels);
    pixel_line(create_rectangle_shape(px + width, py + height, px, py + height), pixel_tab, nb_pixels);
    pixel_line(create_rectangle_shape(px, py + height, px, py), pixel_tab, nb_pixels);
}


