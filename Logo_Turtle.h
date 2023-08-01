#ifndef LOGO_TURTLE_H
#define LOGO_TURTLE_H
#include <curses.h>

int checkinput(const char* sArray[] , const char cmd[]);
void definetrace(char *traceback , const char cmd[]);
void moveturtle(const char cmd[] , int *new_turtle_y , int *new_turtle_x , int pen_down , int value , char traceback , WINDOW* w);

#endif // Fecha a diretiva e finaliza o include guard
