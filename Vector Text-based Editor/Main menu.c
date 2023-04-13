#include <stdio.h>

void display_main_menu(){
    char ans;
    printf("Please select an action:");
    printf("    A-Add a shape");
    printf("    B-Display the list of shapes");
    printf("    C-Delete a shape");
    printf("    D-Drawing the shapes");
    printf("    E-Help");
    printf("What do you want to do ? :");
    scanf("%c",&ans);
    switch(ans){
        case 'A' :
        {
            break;
        }
        case 'B' :
        {
            break;
        }
        case 'C' :
        {
            break;
        }
        case 'D' :
        {
            break;
        }
        case 'E' :
        {
            break;
        }
        default: display_main_menu();
    }
}

void display_add_shape(){

}

void display_list_of_shape(){

}

void display_delete(){

}

void display_drawing_the_shape(char window[]){

}

