#include <curses.h>
#include <string.h>
#include "src/turtle_functions.h"

//Comandos cmd
const char *possibleCommands[] = {
    "up", "dw", "lt", "rt" , 
    "pc", "cl", "sq", "tg" ,
    "dm", "ci", "ex", NULL
};

const char *zNuComands[] = { 
    "pc", "cl", "sq", "tg" ,
    "dm", "ci", "ex", NULL
};

const char * cmdmoveturtle[] = {
    "up", "dw", "lt", "rt" , NULL
};

const char * cmddrawfigure[] = {
    "sq" , "tg" , "dm" , "ci" , NULL
};

int main() {
    WINDOW* w, *prompt;
    
    int turtle_y ; int turtle_x ;
    int sh, sw;
    turtleinit(&sh , &sw , &w , &prompt, &turtle_y , &turtle_x);
    

    // Pen down
    int pen_down = 1;
    char command[100];

    while (1) {
        setprompt(&prompt,command);
        if (!command[0]) {
            continue;
        }
        else {
            char cmd[10];
            int value;

            int checks = sscanf(command, "%s %d", cmd, &value);
            
            if ((checks != 2 || !checkinput(possibleCommands,cmd)) & !(checks >= 1 & checkinput(zNuComands, cmd))) {
                continue;
            }

            // Comandos
            char traceback;
            definetrace(&traceback, cmd);

            // Apaga a posi��o atual
            if (!(strcmp(cmd, "pc") == 0)) {
                mvwaddch(w, turtle_y, turtle_x, pen_down ? traceback : ' ');
            }
    

            if (checkinput(cmdmoveturtle, cmd)){
                moveturtle(cmd , &turtle_y , &turtle_x , pen_down , value, traceback , w);
            }
            else if (checkinput(cmddrawfigure,cmd)){
                drawfigure(cmd , &turtle_y , &turtle_x , pen_down , value, w);
            }
            else if (strcmp(cmd, "cl") == 0) {
                doclear(cmd , &turtle_y , &turtle_x , sh , sw , w);
            }
            else if (strcmp(cmd, "pc") == 0) {
                pen_down = !pen_down;
            }
            else if (strcmp(cmd, "ex") == 0) {
                break;
            }
            else {
                continue;
            }

            // limita movimentação
            movlim(&turtle_y , &turtle_x , sh , sw);

            // Nova posi��o
            mvwaddch(w, turtle_y, turtle_x, '@');

            wrefresh(w);

            napms(100);
        }
    }

    // Limpar e sair
    delwin(prompt);
}