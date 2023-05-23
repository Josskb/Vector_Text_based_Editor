//
// Created by ratch on 17/05/2023.
//

#include <malloc.h>
#include <minmax.h>
#include "pixel.h"


//crée le pixel avec ses coordonées
Pixel* create_pixel(int px, int py){
    Pixel* pixel = (Pixel *) malloc(sizeof(Pixel));
    pixel->px = px;
    pixel->py = py;
    return pixel;
}

//supprime le pixel
void delete_pixel(Pixel* pixel){
    pixel = NULL;
    free(pixel);
}

//supprime la liste de formes
void delete_pixel_shape(Pixel** pixel, int nb_pixels) {
    for (int i = 0; i<nb_pixels; i++) {
        free(pixel[i]);
    }
    free(pixel);
}

//crée un point
Pixel **pixel_point(Shape *shape, int *nb_pixels) {
    Point *pt = (Point*)shape->ptrShape;
    Pixel *p = create_pixel(pt->pos_x, pt->pos_y);
    Pixel **pixels = malloc(sizeof(Pixel*));
    pixels[0] = p;
    *nb_pixels = 1;
    return pixels;
}

//crée une ligne
Pixel **pixel_line(Shape *shape, int *nb_pixels){
    Line *line = (Line*)shape->ptrShape;

    int xa = line->p1->pos_x;
    int ya = line->p1->pos_y;
    int xb = line->p2->pos_x;
    int yb = line->p2->pos_y;

    if (xa > xb){
        int change;
        change = xa;
        xa = xb;
        xb = change;
        change = ya;
        ya = yb;
        yb = change;
    }
    int dx = xb - xa;
    int dy = yb - ya;
    int dmin,dmax;
    if (dx > abs(dy)){
        dmax = dx;
        dmin = abs(dy);
    }
    else{
        dmin = dx;
        dmax = abs(dy);
    }

    int nb_segs = (dmin+1);
    int size = (dmax+1)/nb_segs;
    int *segments = (int*)malloc(nb_segs*sizeof(int));
    for (int i = 0; i < nb_segs;i++){
        segments[i] = size;
    }
    int rest = (dmax+1)%nb_segs;
    int *cumuls = (int*)malloc(nb_segs*sizeof(int));
    cumuls[0] = 0;
    for(int i = 1;i <nb_segs;i++){
        cumuls[i] = (((i+1)*rest)%nb_segs < (i*rest)%nb_segs);
        segments[i] = segments[i] + cumuls[i];
    }

    Pixel **pixels = malloc((dmax+1)* sizeof(Pixel*));
    *nb_pixels = 0;
    int x = xa;
    int y = ya;
    int Haut = dy < 0;
    int Horizontal = dx > abs(dy);
    for(int i = 0;i < nb_segs;i++){
        for(int j =0;j < segments[i];j++){
            pixels[*nb_pixels] = malloc(sizeof(Pixel));
            pixels[*nb_pixels]->px = x;
            pixels[*nb_pixels]->py = y;
            (*nb_pixels)++;
            if (Haut){
                if(Horizontal){
                    x++;
                }
                else{
                    y--;
                }
            }
            else{
                if (Horizontal){
                    x++;
                }
                else{
                    y++;
                }
            }
        }
        if (Haut){
            if(Horizontal){
                y--;
            }
            else{
                x++;
            }
        }
        else{
            if (Horizontal){
                y++;
            }
            else{
                x++;
            }
        }

    }
    return pixels;
}

//crée un cercle
Pixel **pixel_circle(Shape *shape,int *nb_pixels){
    //initialise le cercle
    Circle *circle = (Circle*)shape->ptrShape;
    int x = 0;
    int y = circle->radius;
    int d = circle->radius -1;
    *nb_pixels = 0;
    Pixel *pixel = NULL;
    //opérations mathématiques pour créer tous les points du cercle
    while (x<=y){
        *nb_pixels+=8;
        if (d >= 2*x){
            d-= 2*x+1;
            x++;
        }
        else if (d < 2*(circle->radius-y)){
            d+= 2*y-1;
            y--;
        }
        else{
            d += 2 *(y-x-1);
            y--;
            x++;
        }
    }
    Pixel **pixels = malloc((*nb_pixels)* sizeof(Pixel));
    x = 0;
    y = circle->radius;
    d = circle->radius -1;
    *nb_pixels = 0;
    while (x<=y){
        pixel = create_pixel(circle->p->pos_x+x,circle->p->pos_y+y);
        pixels[(*nb_pixels)++] = pixel;
        pixel = create_pixel(circle->p->pos_x+y,circle->p->pos_y+x);
        pixels[(*nb_pixels)++] = pixel;
        pixel = create_pixel(circle->p->pos_x-x,circle->p->pos_y+y);
        pixels[(*nb_pixels)++] = pixel;
        pixel = create_pixel(circle->p->pos_x-y,circle->p->pos_y+x);
        pixels[(*nb_pixels)++] = pixel;
        pixel = create_pixel(circle->p->pos_x+x,circle->p->pos_y-y);
        pixels[(*nb_pixels)++] = pixel;
        pixel = create_pixel(circle->p->pos_x+y,circle->p->pos_y-x);
        pixels[(*nb_pixels)++] = pixel;
        pixel = create_pixel(circle->p->pos_x-x,circle->p->pos_y-y);
        pixels[(*nb_pixels)++] = pixel;
        pixel = create_pixel(circle->p->pos_x-y,circle->p->pos_y-x);
        pixels[(*nb_pixels)++] = pixel;
        if (d >= 2*x){
            d-= 2*x+1;
            x++;
        }
        else if (d < 2*(circle->radius-y)){
            d+= 2*y-1;
            y--;
        }
        else{
            d += 2 *(y-x-1);
            y--;
            x++;
        }
    }
    return pixels;
}

//crée un carré
Pixel **pixel_square(Shape *shape, int *nb_pixels){

    Square *square = (Square*)shape->ptrShape;
    Shape *rectangle = create_rectangle_shape(square->p->pos_x,square->p->pos_y,square->Len,square->Len);
    Pixel **pixels = pixel_rectangle(rectangle,nb_pixels);
    return pixels;
}

//crée un rectangle
Pixel **pixel_rectangle(Shape *shape, int* nb_pixels){
    //initialise le rectangle
    Rectangle *rectangle = (Rectangle *)shape->ptrShape;
    //crée les différentes lignes
    int nbpixel_1,nbpixel_2,nbpixel_3,nbpixel_4;
    Shape *line1 = create_line_shape(rectangle->p->pos_x,rectangle->p->pos_y,rectangle->p->pos_x,rectangle->p->pos_y+rectangle->len);
    Shape *line2 = create_line_shape(rectangle->p->pos_x,rectangle->p->pos_y+rectangle->len,rectangle->p->pos_x+rectangle->wid,rectangle->p->pos_y+rectangle->len);
    Shape *line3 = create_line_shape(rectangle->p->pos_x+rectangle->wid,rectangle->p->pos_y+rectangle->len,rectangle->p->pos_x+rectangle->wid,rectangle->p->pos_y);
    Shape *line4 = create_line_shape(rectangle->p->pos_x+rectangle->wid,rectangle->p->pos_y,rectangle->p->pos_x,rectangle->p->pos_y);

    Pixel **pixels1 = pixel_line(line1,&nbpixel_1);
    Pixel **pixels2 = pixel_line(line2,&nbpixel_2);
    Pixel **pixels3 = pixel_line(line3,&nbpixel_3);
    Pixel **pixels4 = pixel_line(line4,&nbpixel_4);

    *nb_pixels = nbpixel_1 + nbpixel_2 + nbpixel_3 + nbpixel_4;
    Pixel **pixels = malloc(*nb_pixels* sizeof(Pixel*));

    delete_shape(line1);
    delete_shape(line2);
    delete_shape(line3);
    delete_shape(line4);
    for (int i = 0; i < nbpixel_1 ; i ++) {
        pixels[i] = pixels1[i];
    }
    for (int i = 0; i < nbpixel_2 ; i ++) {
        pixels[i + nbpixel_1] = pixels2[i];
    }
    for (int i = 0; i < nbpixel_3 ; i ++) {
        pixels[i + nbpixel_1 + nbpixel_2] = pixels3[i];
    }
    for (int i = 0; i < nbpixel_4 ; i ++) {
        pixels[i + nbpixel_1 + nbpixel_2 + nbpixel_3] = pixels4[i];
    }
    return pixels;
}

//crée un polygon
Pixel **pixel_polygon(Shape *shp, int* nb_pixels) {
    Polygon *polygon = (Polygon *) shp->ptrShape;

    Pixel ***Tab_pixel_line = malloc(sizeof(Pixel **) * (polygon->n - 1));
    int Number_pixel_line[polygon->n];

    *nb_pixels = 0;
    for (int i = 0; i < polygon->n - 1; i++) {
        Shape *line = create_line_shape(polygon->points[i]->pos_x, polygon->points[i]->pos_y,
                                        polygon->points[i + 1]->pos_x, polygon->points[i + 1]->pos_y);
        Tab_pixel_line[i] = pixel_line(line, &Number_pixel_line[i]);
        delete_shape(line);
        *nb_pixels += Number_pixel_line[i];
    }
    Pixel **pixels = malloc(sizeof(Pixel*)*(*nb_pixels));

    int k = 0;
    for (int i = 0; i < polygon->n-1; i++) {
        for (int j = 0; j < Number_pixel_line[i]; j++) {
            pixels[k++] = Tab_pixel_line[i][j];
        }
    }

    return pixels;
}







