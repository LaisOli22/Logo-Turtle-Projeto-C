#ifndef TURTLE_FUNCTIONS_H
#define TURTLE_FUNCTIONS_H

#include <curses.h>
void turtleinit(int *sh, int *sw , WINDOW** w, WINDOW** prompt,int *turtle_y ,int *turtle_x);
void setprompt(WINDOW** prompt, char command[]);
int checkinput(const char* sArray[] , const char cmd[]);
void definetrace(char *traceback , const char cmd[]);
void moveturtle(const char cmd[] , int *new_turtle_y , int *new_turtle_x , int pen_down , int value , char traceback , WINDOW* w);
void drawfigure(const char cmd[] , int *new_turtle_y , int *new_turtle_x , int pen_down , int value , WINDOW* w);
void doclear(const char cmd[] , int *new_turtle_y , int *new_turtle_x ,int sh , int sw , WINDOW* w);
void movlim(int * turtle_y , int * turtle_x , const int sh , const int sw);
#endif