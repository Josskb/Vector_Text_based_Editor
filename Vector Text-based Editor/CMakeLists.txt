cmake_minimum_required(VERSION 3.24)
project (Vector_Text_based_Editor C)

set(CMAKE_C_STANDARD 11)

add_executable(Vector_Text_based_Editor main.c VTBE.h "Main menu.c" "Main menu.c" "main menu.h" Shapes/Point/Point.c Shapes/Point/Point.h Window.c)
