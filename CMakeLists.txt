cmake_minimum_required(VERSION 3.24)
project (Vector_Text_based_Editor C)

set(CMAKE_C_STANDARD 11)

add_executable(Vector_Text_based_Editor main.c "Main menu.c" "Main menu.c" Shapes/Point.c  Window.c Shapes/Point.c Shapes/Point.c Shapes/Point.c Shapes/Point.c Shapes/Line/Line.c Shapes/Square/Square.c Shapes/Rectangle/Rectangle.c Shapes/Circle/Circle.c Shapes/Polygon/Polygon.c Shapes/Shape.c area.c area.h pixel.c pixel.h)
