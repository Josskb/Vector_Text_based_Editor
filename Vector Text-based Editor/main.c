#include <stdio.h>
#include "Shapes/Shape.h"
#include <malloc.h>
#include "main menu.h"


int main( ) {
    Shape **L = malloc(0*sizeof(Shape*));
    int LS = 0;
    printf("Please select an action:\n");
    printf("    A-Add a shape\n");
    printf("    B-Display the list of shapes\n");
    printf("    C-Delete a shape\n");
    printf("    D-Drawing the shapes\n");
    printf("    E-Help\n");
    printf("    F-Stop\n");
    char ans = input();
    while (ans != 'F'){
        if (ans == 'A'){
            printf("Your choice: A \n");
            printf("Please select an action:\n");
            printf("    1-Add a point \n");
            printf("    2-Add a line \n");
            printf("    3-Add a square \n");
            printf("    4-Add a rectangle \n");
            printf("    5-Add a circle\n");
            printf("    6-Add a polygon\n");
            printf("    7-Return to previous menu\n");
            printf(" What do you want to do ? : ");
            scanf(" %c",&ans);
            printf("\n");
            if (ans=='1'){
                int X1,X2;
                printf("Enter the information of the point :\n") ;
                printf("    Enter the coord of the point x1 y1 :");
                scanf(" %d %d",&X1,&X2);
                Shape *s = create_point_shape(X1,X2);
                L = realloc(L,(LS+1)*sizeof(Shape*));
                L[LS] = s;
                LS++;

            }
            else if (ans =='2'){
                int X1,X2,Y1,Y2;
                printf("Enter the information of the points :\n") ;
                printf("    Enter x1 y1 x2 y2:");
                scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
                printf("\n");
                Shape *s = create_line_shape(X1,Y1,X2,Y2);
                L = realloc(L,(LS+1)*sizeof(Shape*));
                L[LS] = s;
                LS++;

            }
            else if (ans =='3') {
                int X1, Y1, length;
                printf("Enter the information of the points :\n");
                printf(">> Enter x1 y1:");
                scanf("%d %d", &X1, &Y1);
                printf("\n");
                printf(">> Enter length of the square:");
                scanf("%d", &length);
                printf("\n");
                Shape *s = create_square_shape(X1, Y1, length);
                L = realloc(L,(LS+1)*sizeof(Shape*));
                L[LS] = s;
                LS++;

            }
            else if (ans == '4'){
                int X1,Y1,width,height;
                printf("Enter the information of the first points :\n") ;
                printf("    Enter x1 y1:");
                scanf("%d %d",&X1,&Y1);
                printf("\n");
                printf("    Enter width of the rectangle:");
                scanf("%d",&width);
                printf("\n");
                printf("    Enter height of the rectangle:");
                scanf("%d",&height);
                printf("\n");
                Shape *s = create_rectangle_shape(X1,Y1 , width, height);
                L = realloc(L,(LS+1)*sizeof(Shape*));
                L[LS] = s;
                LS++;

            }
            else if (ans == '5') {
                int X1, Y1, radius;
                printf("Enter the information of the first points :\n");
                printf("    Enter x1 y1:");
                scanf("%d %d", &X1, &Y1);
                printf("\n");
                printf("    Enter the radius of the circle:");
                scanf("%d", &radius);
                printf("\n");
                Shape *s = create_circle_shape(X1, Y1, radius);
                L = realloc(L,(LS+1)*sizeof(Shape*));
                L[LS] = s;
                LS++;

            }
            else if (ans == '6'){
                int n;
                printf("Enter the number of points :");
                scanf("%d",&n);
                Shape *s = create_polygon_shape(n);
                L = realloc(L,(LS+1)*sizeof(Shape*));
                L[LS] = s;
                LS++;
            }
        }
        else if (ans == 'B') {
            printf("List :\n");
            if (LS == 0) {
                printf("Empty\n");
            }
            else {
                for (int j = 0; j < LS; j++) {
                    print_shape(L[j]);
                }
            }
        }
        else if (ans == 'C') {
            printf("C");
        }
        else if (ans == 'D') {
            printf("D");
        }
        else if (ans == 'E'){
            printf("    A-Add a shape\n");
            printf("    B-Display the list of shapes\n");
            printf("    C-Delete a shape\n");
            printf("    D-Drawing the shapes\n");
            printf("    E-Help\n");
            printf("    F-Stop\n");
        }
        ans = input();
    }
}


