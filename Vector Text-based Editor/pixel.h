

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
Pixel **pixel_point(Shape *shape, int *nb_pixels);
Pixel **pixel_line(Shape *shape, int *nb_pixels);
Pixel **pixel_circle(Shape *shape,int *nb_pixels);
Pixel **pixel_square(Shape *shape, int *nb_pixels);
Pixel **pixel_rectangle(Shape *shape, int* nb_pixels);
Pixel **pixel_polygon(Shape *shp, int* nb_pixels);
void delete_pixel_shape(Pixel** pixel, int nb_pixels);


#endif //VECTOR_TEXT_BASED_EDITOR_PIXEL_H
