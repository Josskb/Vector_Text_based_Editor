// Created by Jojo on 23/05/2023.
//

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "commande.h"

// create a variable of type command.
Command* create_commande(){
    Command *command = malloc(sizeof(Command));
    command->int_size = 0;
    command->str_size = 0;
    return command;
}

// allows to insert the character string given in parameter into the array str_params and increment str_size;
void add_str_param(Command* cmd, char* p){
    cmd->str_params[cmd->str_size] = p;
    cmd->str_size++;
}

// inserts the integer given in parameter into the array int_params and increments int_size;
void add_int_param(Command* cmd, int p){
    cmd->int_params[cmd->int_size] = p;
    cmd->int_size++;
}

// supprime la commande
void free_cmd(Command* cmd){
    for (int i = 0; i < cmd->str_size; i++){
        free(cmd->str_params[i]);
    }
    free(cmd);
}

// allow to know if the string is an integer
int Type_Int(char *string){
    int j = 0;
    while (string[j] != '\0'){
        if (string[j] >= '0' && string[j] <= '9'){
        } else{
            return 0;
        }
        j++;
    }
    return 1;
}

// asks the user to type a line, then parse the line into the parameter cmd.
void read_from_stdin(Command* cmd){
    char answer[50];
    const char *space = " \n";
    cmd->int_size = 0;
    fgets(answer, 50, stdin);
    // délimite en fonction des espaces
    char *series_of_token = strtok(answer, space);
    int i = 0;
    while(series_of_token[i] != '\0'){
        cmd->name[i] = series_of_token[i];
        i++;
    }
    cmd->name[i] = '\0';
    series_of_token = strtok(NULL, space);
    while (series_of_token != NULL) {
        if (Type_Int(series_of_token)){
            add_int_param(cmd, atoi(series_of_token)); // convert a string to an int
        }
        else {
            add_str_param(cmd, series_of_token);
        }
        series_of_token = strtok(NULL, space);
    }
}

// execute the command entered by the user.
int read_exec_command(Command* cmd, Area* zone){
    read_from_stdin(cmd);
    // compare the string pointed to the second one
    // clear
    if (!strcmp(cmd->name, "clear")){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        return 1;
    }
        // exit
    else if (!strcmp(cmd->name, "exit")){
        return 0;
    }
        // point
    else if (!strcmp(cmd->name, "point")){
        if (cmd->int_size == 2){
            add_shape_to_area(zone, create_point_shape(cmd->int_params[0], cmd->int_params[1]));
        }
        return 1;
    }
        // line
    else if (!strcmp(cmd->name, "line")){
        if (cmd->int_size == 4){
            add_shape_to_area(zone, create_line_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2], cmd->int_params[3]));
        }
        return 1;
    }
        // square
    else if (!strcmp(cmd->name, "square")){
        if (cmd->int_size == 3){
            add_shape_to_area(zone, create_square_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2]));
        }
        return 1;
    }
        // rectangle
    else if (!strcmp(cmd->name, "rectangle")){
        if (cmd->int_size == 4){
            add_shape_to_area(zone, create_rectangle_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2], cmd->int_params[3]));
        }
        return 1;
    }
        // circle
    else if (!strcmp(cmd->name, "circle")){
        if (cmd->int_size == 3){
            add_shape_to_area(zone, create_circle_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2]));
        }
        return 1;
    }
        // polygon
    else if (!strcmp(cmd->name, "polygon")){
        if (cmd->int_size >= 4 && cmd->int_size % 2 == 0){
            add_shape_to_area(zone, create_polygon_shape(cmd->int_params,cmd->int_size));
        }
        return 1;
    }
        // plot
    else if (!strcmp(cmd->name, "plot")){
        draw_area(zone);
        print_area(zone);
        return 1;
    }
        // list
    else if (!strcmp(cmd->name, "list")){
        for (int i = 0; i < zone->nb_shape; i++){
            print_shape(zone->shapes[i]);
        }
        return 1;
    }
        // erase
    else if (!strcmp(cmd->name, "erase")){
        erase_area(zone);
        return 1;
    }
        // delete
    else if (!strcmp(cmd->name, "delete")){
        for (int i = 0; i < zone->nb_shape; i++){
            if (zone->shapes[i]->id == cmd->int_params[0]){
                delete_shape(zone->shapes[i]);
                zone->shapes[i] = NULL;
            }
        }
        return 1;
    }
        // help
    else if (!strcmp(cmd->name, "help")){
        printf("##########################################################################################################\n"
               "# => list : display zone list of all the geometric shapes that make up the image and all their information#\n"
               "# => exit : exit the program                                                                              #\n"
               "# => point x y : add zone point                                                                           #\n"
               "# => line x1 y1 x2 y2 : add zone segment connecting two points (x1, y1) and (x2, y2)                      #\n"
               "# => circle x y radius : add zone circle of centre (x, y) and zone radius radius                          #\n"
               "# => square x y length : add zone square whose upper left corner is (x, y) and whose side is length.      #\n"
               "# => rectangle x y height width  : add zone rectangle whose upper left corner is (x, y), whose width      #\n"
               "# is width and whose height is height                                                                      #\n"
               "# => polygon x1 y1 x2 y2 x3 y3 ... ... : add zone polygon with the list of given points                   #\n"
               "# => plot : refresh the screen to display all the geometric shapes in the image (depending on the         #\n"
               "# display rules)                                                                                           #\n"
               "# => list : display zone list of all the geometric shapes that make up the image and all their information#\n"
               "# => delete id : delete zone shape from its identifier id.                                                #\n"
               "# => erase : remove all shapes from an image.                                                             #\n"
               "##########################################################################################################\n");
    }
    else{
        printf("This command does not exist.\n");
    }
    return 1;
}
