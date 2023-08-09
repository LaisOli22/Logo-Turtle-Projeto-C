#include <curses.h>
#include <string.h>
#include "turtle_functions.h"

void turtleinit(int *sh, int *sw , WINDOW** w, WINDOW** prompt,int *turtle_y ,int *turtle_x){
    initscr();
    curs_set(1);
    nodelay(stdscr, 1);
    
    getmaxyx(stdscr, *sh, *sw);
    *w = newwin(*sh - 3, *sw, 0, 0);
    box(*w, 0, 0);
    wrefresh(*w);

    // Window de comando
    *prompt = newwin(3, *sw, *sh - 3, 0);
    box(*prompt, 0, 0);
    mvwprintw(*prompt, 1, 1, " Comandos: ");
    wrefresh(*prompt);

    // Turtle no centro
    *turtle_y = (*sh - 3) / 2;
    *turtle_x = *sw / 2;
    mvwaddch(*w, *turtle_y, *turtle_x, '@');
    wrefresh(*w);

}

void setprompt(WINDOW** prompt, char command[]){
    wmove(*prompt, 1, 11);
    wclrtoeol(*prompt); // limpa o input
    wrefresh(*prompt);
    echo();
    wgetnstr(*prompt, command, 100);
    noecho();
}

int checkinput(const char* sArray[] , const char cmd[]){

    int i = 0;
    while (sArray[i] != NULL) {
        if (strcmp(sArray[i], cmd) == 0) {
            return 1;
        }
        i++;
    }
    return 0;
}

void definetrace(char *traceback , const char cmd[]){
    if (strcmp(cmd, "up") == 0  || strcmp(cmd, "dw") == 0) {
            *traceback = '|';
        }

        else if (strcmp(cmd, "lt") == 0 || strcmp(cmd, "rt") == 0) {
            *traceback = '-';
        }
        
        else if (strcmp(cmd, "tg") == 0 || strcmp(cmd, "rt") == 0) {
            *traceback = '/';
        }

        else{
            *traceback = ' ';
        }
}

void moveturtle(const char cmd[] , int *turtle_y , int *turtle_x , int pen_down , int value , char traceback , WINDOW* w){
    if (strcmp(cmd, "up") == 0) {
        for (int i = 0; i < value; i++) {
            *turtle_y -= 1;
            if (pen_down) {
                mvwaddch(w, *turtle_y, *turtle_x, traceback);
            }
        }  
    }
    else if (strcmp(cmd, "dw") == 0) {
        //down
        for (int i = 0; i < value; i++) {
            *turtle_y += 1;
            if (pen_down) {
                mvwaddch(w, *turtle_y, *turtle_x, traceback);
            }
        }
    }
    else if (strcmp(cmd, "lt") == 0) {//left
        for (int i = 0; i < value; i++) {
            *turtle_x -= 1;
            if (pen_down) {
                mvwaddch(w, *turtle_y, *turtle_x, traceback);
            }
        }
    }
    else if (strcmp(cmd, "rt") == 0) {//rigth
        for (int i = 0; i < value; i++) {
            *turtle_x += 1;
            if (pen_down) {
                mvwaddch(w, *turtle_y, *turtle_x, traceback);
            }
        }
    }


}

void drawfigure(const char cmd[] , int *turtle_y , int *turtle_x , int pen_down , int value , WINDOW* w){
    if (strcmp(cmd, "sq") == 0) {//Quadrado
        for (int i = 0; i < 12; i++) {
            *turtle_x += 1;
            mvwaddch(w, *turtle_y, *turtle_x, '-');
        }
        for (int i = 0; i < 6; i++) {
            *turtle_y += 1;
            mvwaddch(w, *turtle_y, *turtle_x, '|');
        }
        for (int i = 0; i < 12; i++) {
            *turtle_x -= 1;
            mvwaddch(w, *turtle_y, *turtle_x, '-');
        }
        for (int i = 0; i < 6; i++) {
            *turtle_y -= 1;
            mvwaddch(w, *turtle_y, *turtle_x, '|');
        }
    }
    else if (strcmp(cmd, "tg") == 0) {//Triangulo
        for (int i = 0; i < 6; i++) {
            *turtle_y -= 1;
            *turtle_x += 1;
            mvwaddch(w, *turtle_y, *turtle_x, '/');
        }
        for (int i = 0; i < 7; i++) {
            *turtle_y += 1;
            *turtle_x += 1;
            mvwaddch(w, *turtle_y, *turtle_x, '\\');
        }
        for (int i = 0; i < 14; i++) {
            *turtle_x -= 1;
            mvwaddch(w, *turtle_y, *turtle_x, '-');
        }
    }
    else if (strcmp(cmd, "dm") == 0) {
        for (int i = 0; i < 6; i++) {
            *turtle_y -= 1;
            *turtle_x += 1;
            mvwaddch(w, *turtle_y, *turtle_x, '/');
        }
        for (int i = 0; i < 6; i++) {
            *turtle_y += 1;
            *turtle_x += 1;
            mvwaddch(w, *turtle_y, *turtle_x, '\\');
        }
        for (int i = 0; i < 6; i++) {
            *turtle_y += 1;
            *turtle_x -= 1;
            mvwaddch(w, *turtle_y, *turtle_x, '/');
        }
        for (int i = 0; i < 6; i++) {
            *turtle_y -= 1;
            *turtle_x -= 1;
            mvwaddch(w, *turtle_y, *turtle_x, '\\');
        }
    }
    else if (strcmp(cmd, "ci") == 0) {
        for (int i = 0; i < 7; i++) {
            *turtle_x += 1;
            mvwaddch(w, *turtle_y, *turtle_x, '-');
        }
        for (int i = 0; i < 2; i++) {
            *turtle_y += 1;
            *turtle_x += 1;
            mvwaddch(w, *turtle_y, *turtle_x, '\\');
        }
        for (int i = 0; i < 2; i++) {
            *turtle_y += 1;
            mvwaddch(w, *turtle_y, *turtle_x, '|');
        }
        for (int i = 0; i < 2; i++) {
            *turtle_y += 1;
            *turtle_x -= 1;
            mvwaddch(w, *turtle_y, *turtle_x, '/');
        }
        for (int i = 0; i < 7; i++) {
            *turtle_x -= 1;
            mvwaddch(w, *turtle_y, *turtle_x, '-');
        }
        for (int i = 0; i < 2; i++) {
            *turtle_y -= 1;
            *turtle_x -= 1;
            mvwaddch(w, *turtle_y, *turtle_x, '\\');
        }
        for (int i = 0; i < 2; i++) {
            *turtle_y -= 1;
            mvwaddch(w, *turtle_y, *turtle_x, '|');
        }
        for (int i = 0; i < 2; i++) {
            *turtle_y -= 1;
            *turtle_x += 1;
            mvwaddch(w, *turtle_y, *turtle_x, '/');
        }
    }
}

void doclear(const char cmd[] , int *turtle_y , int *turtle_x ,const int sh , const int sw , WINDOW* w) {
    wclear(w);
    box(w, 0, 0);
    *turtle_x = sw / 2;
    *turtle_y = (sh - 3) / 2;
    mvwaddch(w, *turtle_y, *turtle_x, '@');
    
}

void movlim(int * turtle_y , int * turtle_x , const int sh , const int sw){
    if (*turtle_y < 0) *turtle_y = 0;
    if (*turtle_y >= sh - 3) *turtle_y = sh - 4;
    if (*turtle_x < 0) *turtle_x = 0;
    if (*turtle_x >= sw) *turtle_x = sw - 1;
}
