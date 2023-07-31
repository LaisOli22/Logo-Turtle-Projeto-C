#include <curses.h>
#include <string.h>

int checkcmd(const char cmd[]){
    char possibleCommands[][11] = {
        "up", "dw", "lt", "rt"
        "pu", "cl", "sq", "tg"
        "dm", "ci", "ex"
    };

    for(int i = 0 ; i <= 10 ; i++) {
        if (strcmp(possibleCommands[i], cmd) == 0){
            return 0;
            break;
        }
    }

    return 1;

}

int main() {
    WINDOW* w, *prompt;

    initscr();
    curs_set(1);
    nodelay(stdscr, 1);

    int sh, sw;
    getmaxyx(stdscr, sh, sw);
    w = newwin(sh - 3, sw, 0, 0);
    box(w, 0, 0);
    wrefresh(w);

    // Window de comando
    prompt = newwin(3, sw, sh - 3, 0);
    box(prompt, 0, 0);
    mvwprintw(prompt, 1, 1, " Comandos: ");
    wrefresh(prompt);

    // Turtle no centro
    int turtle_y = (sh - 3) / 2;
    int turtle_x = sw / 2;
    mvwaddch(w, turtle_y, turtle_x, '@');
    wrefresh(w);

    // Pen down
    int pen_down = 1;
    char command[100];

    while (1) {
        wmove(prompt, 1, 11);
        wclrtoeol(prompt); // limpa o input
        wrefresh(prompt);
        echo();
        wgetnstr(prompt, command, sizeof(command));
        noecho();

        if (!command[0]) {
            continue;
        }
        else {
            char cmd[10];
            int value;
            if (sscanf(command, "%s %d", cmd, &value) != 2) {
                continue;
            }

            // Verifica se o comando e valido
            if (checkcmd(cmd)) {
                continue;
            }

            // Comandos
            int new_turtle_y = turtle_y;
            int new_turtle_x = turtle_x;

            char traceback;
            if (strcmp(cmd, "up") == 0  || strcmp(cmd, "dw") == 0) {
                traceback = '|';
            }

            else if (strcmp(cmd, "lt") == 0 || strcmp(cmd, "rt") == 0) {
                traceback = '-';
            }

            // Apaga a posi��o atual
            mvwaddch(w, turtle_y, turtle_x, pen_down ? traceback : ' ');

            if (strcmp(cmd, "up") == 0) {
                for (int i = 0; i < value; i++) {
                    new_turtle_y -= 1;
                    if (pen_down) {
                        mvwaddch(w, new_turtle_y, new_turtle_x, traceback);
                    }
                }
            }
            else if (strcmp(cmd, "dw") == 0) {//down
                for (int i = 0; i < value; i++) {
                    new_turtle_y += 1;
                    if (pen_down) {
                        mvwaddch(w, new_turtle_y, new_turtle_x, traceback);
                    }
                }
            }
            else if (strcmp(cmd, "lt") == 0) {//left
                for (int i = 0; i < value; i++) {
                    new_turtle_x -= 1;
                    if (pen_down) {
                        mvwaddch(w, new_turtle_y, new_turtle_x, traceback);
                    }
                }
            }
            else if (strcmp(cmd, "rt") == 0) {//rigth
                for (int i = 0; i < value; i++) {
                    new_turtle_x += 1;
                    if (pen_down) {
                        mvwaddch(w, new_turtle_y, new_turtle_x, traceback);
                    }
                }
            }
            else if (strcmp(cmd, "sq") == 0) {//Quadrado
                for (int i = 0; i < 12; i++) {
                    new_turtle_x += 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '-');
                }
                for (int i = 0; i < 6; i++) {
                    new_turtle_y += 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '|');
                }
                for (int i = 0; i < 12; i++) {
                    new_turtle_x -= 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '-');
                }
                for (int i = 0; i < 6; i++) {
                    new_turtle_y -= 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '|');
                }
            }
            else if (strcmp(cmd, "tg") == 0) {//Triangulo
                for (int i = 0; i < 6; i++) {
                    new_turtle_y -= 1;
                    new_turtle_x += 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '/');
                }
                for (int i = 0; i < 7; i++) {
                    new_turtle_y += 1;
                    new_turtle_x += 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '\\');
                }
                for (int i = 0; i < 14; i++) {
                    new_turtle_x -= 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '-');
                }
            }
            else if (strcmp(cmd, "dm") == 0) {
                for (int i = 0; i < 6; i++) {
                    new_turtle_y -= 1;
                    new_turtle_x += 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '/');
                }
                for (int i = 0; i < 6; i++) {
                    new_turtle_y += 1;
                    new_turtle_x += 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '\\');
                }
                for (int i = 0; i < 6; i++) {
                    new_turtle_y += 1;
                    new_turtle_x -= 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '/');
                }
                for (int i = 0; i < 6; i++) {
                    new_turtle_y -= 1;
                    new_turtle_x -= 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '\\');
                }
            }
            else if (strcmp(cmd, "ci") == 0) {
                for (int i = 0; i < 7; i++) {
                    new_turtle_x += 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '-');
                }
                for (int i = 0; i < 2; i++) {
                    new_turtle_y += 1;
                    new_turtle_x += 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '\\');
                }
                for (int i = 0; i < 2; i++) {
                    new_turtle_y += 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '|');
                }
                for (int i = 0; i < 2; i++) {
                    new_turtle_y += 1;
                    new_turtle_x -= 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '/');
                }
                for (int i = 0; i < 7; i++) {
                    new_turtle_x -= 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '-');
                }
                for (int i = 0; i < 2; i++) {
                    new_turtle_y -= 1;
                    new_turtle_x -= 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '\\');
                }
                for (int i = 0; i < 2; i++) {
                    new_turtle_y -= 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '|');
                }
                for (int i = 0; i < 2; i++) {
                    new_turtle_y -= 1;
                    new_turtle_x += 1;
                    mvwaddch(w, new_turtle_y, new_turtle_x, '/');
                }
            }
            else if (strcmp(cmd, "cl") == 0) {
                wclear(w);
                box(w, 0, 0);
                new_turtle_x = sw / 2;
                new_turtle_y = (sh - 3) / 2;
                mvwaddch(w, new_turtle_y, new_turtle_x, '@');
            }
            else if (strcmp(cmd, "pu") == 0) {
                pen_down = !pen_down;
            }
            else if (strcmp(cmd, "ex") == 0) {
                break;
            }
            else {
                continue;
            }

            // Movimenta��o dentro da tela
            if (new_turtle_y < 0) new_turtle_y = 0;
            if (new_turtle_y >= sh - 3) new_turtle_y = sh - 4;
            if (new_turtle_x < 0) new_turtle_x = 0;
            if (new_turtle_x >= sw) new_turtle_x = sw - 1;

            // Nova posi��o
            turtle_y = new_turtle_y;
            turtle_x = new_turtle_x;
            mvwaddch(w, turtle_y, turtle_x, '@');

            wrefresh(w);

            napms(100);
        }
    }

    // Limpar e sair
    delwin(prompt);

}


