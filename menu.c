#include <curses.h>
#include <string.h>

char* menu[] = {"Comandos", "Modo teclado", "Modo texto", "Sair"};
int menu_size = sizeof(menu) / sizeof(menu[0]);

void print_menu(WINDOW* win, int selected_row_idx) {

    clear();
    int h, w;
    getmaxyx(win, h, w);
    box(win, 0, 0);
    mvwprintw(win, (h / 2) - 7, (w / 2) - 9, "L O G O  T U R T L E");

    for (int row = 0; row < menu_size; row++) {
        int x = w / 2 - strlen(menu[row]) / 2;
        int y = (h / 2) - (menu_size / 2) + row;
        if (row == selected_row_idx) {
            wattron(win, A_STANDOUT);
            mvwprintw(win, y, x, menu[row]);
            wattroff(win, A_STANDOUT);
        } else {
            mvwprintw(win, y, x, menu[row]);
        }
    }
    wrefresh(win);
}

int main() {
    initscr();
    noecho();
    curs_set(0);

    int current_row_idx = 0;

    // Window para mensagens
    int msg_height, msg_width;
    getmaxyx(stdscr, msg_height, msg_width);
    int msg_y = (LINES - msg_height) / 2;
    int msg_x = (COLS - msg_width) / 2;
    WINDOW* msg_win = newwin(msg_height, msg_width, msg_y, msg_x);

    while (1) {
        print_menu(stdscr, current_row_idx);
        int key = getch();

        if (key == KEY_UP || key == 'w' || key == 'W') {
            if (current_row_idx > 0) {
                current_row_idx -= 1;
            }
        } else if (key == KEY_DOWN || key == 's' || key == 'S') {
            if (current_row_idx < menu_size - 1) {
                current_row_idx += 1;
            }
        } else if (key == KEY_ENTER || key == '\n' || key == '\r') {
            // Sa�da
            if (current_row_idx == menu_size - 1) {
                werase(msg_win);
                box(msg_win, 0, 0);
                mvwprintw(msg_win, 1, 2, "Voc� selecionou: %s", menu[current_row_idx]);
                mvwprintw(msg_win, 3, 2, "At� logo!");
                wrefresh(msg_win);
                getch();
                break;
            } else if (current_row_idx == menu_size - 2) {
                // Modo texto
                werase(msg_win);
                box(msg_win, 0, 0);
                mvwprintw(msg_win, 1, 2, "Voc� selecionou: %s", menu[current_row_idx]);
                mvwprintw(msg_win, 3, 2, "Iniciando o jogo...");
                mvwprintw(msg_win, 5, 2, "Pressione Enter");
                wrefresh(msg_win);
                getch();
            } else if (current_row_idx == menu_size - 3) {
                // Modo teclado
                werase(msg_win);
                box(msg_win, 0, 0);
                mvwprintw(msg_win, 1, 2, "Voc� selecionou: %s", menu[current_row_idx]);
                mvwprintw(msg_win, 3, 2, "Iniciando o jogo...");
                mvwprintw(msg_win, 5, 2, "Pressione Enter");
                wrefresh(msg_win);
                getch();
            } else if (current_row_idx == menu_size - 4) {
                // Comandos
                werase(msg_win);
                box(msg_win, 0, 0);
                mvwprintw(msg_win, 1, 2, "Voc� selecionou: %s", menu[current_row_idx]);
                mvwprintw(msg_win, 2, 2, "MODO TECLADO:");
                mvwprintw(msg_win, 4, 2, "Tecla W = Cima");
                mvwprintw(msg_win, 5, 2, "Tecla A = Esquerda");
                mvwprintw(msg_win, 6, 2, "Tecla S = Baixo");
                mvwprintw(msg_win, 7, 2, "Tecla D = Direita");
                mvwprintw(msg_win, 8, 2, "Barra de espa�o = Para de desenhar");
                mvwprintw(msg_win, 10, 2, "Diagonais:");
                mvwprintw(msg_win, 11, 2, "Tecla E = Cima-direita");
                mvwprintw(msg_win, 12, 2, "Tecla Q = Cima-esquerda");
                mvwprintw(msg_win, 13, 2, "Tecla C = Baixo-direita");
                mvwprintw(msg_win, 14, 2, "Tecla Z = Baixo-esquerda");

                mvwprintw(msg_win, 16, 2, "MODO TEXTO:");
                mvwprintw(msg_win, 17, 2, "ex. 'up 3' (qualquer comando + valor)");
                mvwprintw(msg_win, 19, 2, "up = Cima");
                mvwprintw(msg_win, 20, 2, "dw = Baixo");
                mvwprintw(msg_win, 21, 2, "rt = Direita");
                mvwprintw(msg_win, 22, 2, "lt = Esquerda");
                mvwprintw(msg_win, 24, 2, "Desenhos:");
                mvwprintw(msg_win, 25, 2, "sq = Quadrado");
                mvwprintw(msg_win, 26, 2, "tg = Tri�ngulo");
                mvwprintw(msg_win, 27, 2, "dm = Diamante");
                mvwprintw(msg_win, 28, 2, "ci = C�rculo");
                mvwprintw(msg_win, 30, 2, "Ferramentas:");
                mvwprintw(msg_win, 31, 2, "pu = Para de desenhar / Volta a desenhar");
                mvwprintw(msg_win, 32, 2, "cl = Limpa os desenhos");
                mvwprintw(msg_win, 33, 2, "ex = Sair");
                wrefresh(msg_win);
                getch();
            }
        }
    }
    // Limpar e sair
    delwin(msg_win);
    endwin();
    return 0;
}