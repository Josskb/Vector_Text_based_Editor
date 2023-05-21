

#ifndef VECTOR_TEXT_BASED_EDITOR_PIXEL_H
#define VECTOR_TEXT_BASED_EDITOR_PIXEL_H


#include "Shapes/Shape.h"

struct pixel {
    int px;
    int py;
};
typedef struct pixel Pixel;

Pixel* create_pixel(int px, int py);
void delete_pixel(Pixel* pixel);
void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels);
void pixel_line(Shape* line, Pixel*** pixel_tab, int* nb_pixels);
void pixel_circle(Shape* shape, Pixel*** pixel_tab, int*nb_pixels);
void pixel_square(Shape* shape, Pixel*** pixel_tab, int* nb_pixels);
void pixel_rectangle(Shape* shape, Pixel*** pixel_tab, int* nb_pixels);
void pixel_polygon(Shape* shape, Pixel*** pixel_tab, int* nb_pixels);


#endif //VECTOR_TEXT_BASED_EDITOR_PIXEL_H
