#define X 100
#define Y 100
#include <stdio.h>

void create_window(){
    char window[X][Y];
    for (int i = 0; i < X; i++){
        for (int k = 0; k < Y; k++){
            window[i][k] = '*';
        }
    }
}

void display_window(char window[][]){
    for (int i = 0; i < X; i++){
        for (int k = 0; k < Y; k++) {
            printf("%c ", window[i][k]);
        }
        printf("\n");
    }
}
