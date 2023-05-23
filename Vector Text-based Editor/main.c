#include <stdio.h>
#include "Shapes/Shape.h"
#include <malloc.h>
#include "main menu.h"
#include "area.h"


int main( ) {
    Shape **L = malloc(0*sizeof(Shape*));
    Area* area = NULL;
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
            int id_to_delete = 0;
            printf("C");
            if (LS == 0) {
                printf("There is no shape to delete");
            }
            else{
                printf("Which shape do you want to delete ? (enter is ID) :");
                scanf(" %c%*c",&id_to_delete);
                printf("Your shape of ID: %d ",id_to_delete);
                if (id_to_delete <= LS){
                    delete_shape(L[id_to_delete-1]);
                    *(L + id_to_delete - 1) = NULL;
                    LS--;
                }
            }
        }
        else if (ans == 'D') {
            printf("Your choice: D \n");
            printf("Please select an action:\n");
            printf("    1-Create an Area \n");
            printf("    2-Add shapes to the area \n");
            printf("    3-Display the area \n");
            printf(" What do you want to do ? : ");
            scanf("%c%*c",&ans);
            switch(ans){
                case ('1') :
                    if (area == NULL){
                        int x = 0;
                        int y = 0;
                        printf("Give the size of the area (x, y) :");
                        scanf("%d %d",&x,&y);
                        area = create_area(x,y);
                    }
                    else{
                        printf("An area is already created");
                    }
                    break;
                case ('2') :
                    if (area == NULL){
                        printf("You should create an area by typing 1 !");
                    }
                    else {
                        for (int k = 0; k < LS; k++){
                            add_shape_to_area(area, L[k]);
                        }
                    }
                    break;
                case '3' :
                    if (area == NULL){
                        printf("You should create an area by typing 1 !");
                    }
                    else {
                        draw_area(area);
                        print_area(area);
                    }
                    break;
                }
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


