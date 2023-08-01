#include <curses.h>

int main() {
    WINDOW* w;
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, 1);
    timeout(100);

    int sh, sw;
    getmaxyx(stdscr, sh, sw);
    w = newwin(sh, sw, 0, 0);
    box(w, 0, 0);
    wrefresh(w);

    // Turtle no centro
    int turtle_y = sh / 2;
    int turtle_x = sw / 2;
    mvwaddch(w, turtle_y, turtle_x, '@');
    wrefresh(w);

    // Pen down
    int pen_down = 1;
    while (1) {
        int key = wgetch(w);

        // Posição atual
        int new_turtle_y = turtle_y;
        int new_turtle_x = turtle_x;

        if (key == ' '){
            pen_down = !pen_down;
        }

        // Movimentos
        if (key != -1) {
                if (pen_down){
                    if (key == KEY_UP || key == 'w' || key == 'W') {
                        mvwaddch(w, new_turtle_y, new_turtle_x, '|');
                    }
                    else if (key == KEY_DOWN || key == 's' || key == 'S') {
                        mvwaddch(w, new_turtle_y, new_turtle_x, '|');
                    }
                    else if (key == KEY_LEFT || key == 'a' || key == 'A') {
                        mvwaddch(w, new_turtle_y, new_turtle_x, '-');
                    }
                    else if (key == KEY_RIGHT || key == 'd' || key == 'D') {
                        mvwaddch(w, new_turtle_y, new_turtle_x, '-');
                    }
                      //diagonal cima-direita
                    else if (key == 'e' || key == 'E') {
                        mvwaddch(w, new_turtle_y, new_turtle_x, '/');
                    }
                    //Diagonal cima-esquerda
                    else if (key == 'q' || key == 'Q') {
                        mvwaddch(w, new_turtle_y, new_turtle_x, '\\');
                    }
                    //Diagonal baixo-esquerda
                    else if (key == 'z' || key == 'Z') {
                        mvwaddch(w, new_turtle_y, new_turtle_x, '/');
                    }
                    //Diagonal baixo-direita
                    else if (key == 'c' || key == 'C') {
                        mvwaddch(w, new_turtle_y, new_turtle_x, '\\');
                    }
                }

            if (!pen_down){
                mvwaddch(w, new_turtle_y, new_turtle_x, ' ');
            }

            if (key == KEY_UP || key == 'w' || key == 'W') {
                new_turtle_y -= 1;
            }
            else if (key == KEY_DOWN || key == 's' || key == 'S') {
                new_turtle_y += 1;
            }
            else if (key == KEY_LEFT || key == 'a' || key == 'A') {
                new_turtle_x -= 1;
            }
            else if (key == KEY_RIGHT || key == 'd' || key == 'D') {
                new_turtle_x += 1;
            }
            //diagonal cima-direita
            else if (key == 'e' || key == 'E') {
                new_turtle_y -= 1;
                new_turtle_x += 1;
            }
            //Diagonal cima-esquerda
            else if (key == 'q' || key == 'Q') {
                new_turtle_y -= 1;
                new_turtle_x -= 1;
            }
            //Diagonal baixo-esquerda
            else if (key == 'z' || key == 'Z') {
                new_turtle_y += 1;
                new_turtle_x -= 1;
            }
            //Diagonal baixo-direita
            else if (key == 'c' || key == 'C') {
                new_turtle_y += 1;
                new_turtle_x += 1;
            }
            else {
                continue;
            }

            // Movimentaçăo dentro da tela
            if (new_turtle_y < 0 || new_turtle_y >= sh || new_turtle_x < 0 || new_turtle_x >= sw) {
                break;
            }

            // Nova posiçăo
            turtle_y = new_turtle_y;
            turtle_x = new_turtle_x;
            mvwaddch(w, turtle_y, turtle_x, '@');

            wrefresh(w);

            napms(100);
        }
    }

    endwin();
    return 0;
}

