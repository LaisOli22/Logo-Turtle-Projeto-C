import curses

def main(stdscr):
    curses.curs_set(0)
    stdscr.nodelay(True)
    stdscr.timeout(100)

    sh, sw = stdscr.getmaxyx()
    w = curses.newwin(sh, sw, 0, 0)
    w.border()

    # Turtle no centro
    turtle = [sh // 2, sw // 2]
    w.addch(turtle[0], turtle[1], '@')
    w.refresh()

    # Pen down
    pen_down = True
    while True:
        key = w.getch()

        # Posição atual
        new_turtle = [turtle[0], turtle[1]]

        # Pen up
        if key == ord(" "): #Space bar
            pen_down = not pen_down
            continue

        # Movimentação
        if key != -1:
            if key == curses.KEY_UP or key == ord('w') or key == ord('W'):
                new_turtle[0] -= 1
                traceback = '|'
            elif key == curses.KEY_DOWN or key == ord('s') or key == ord('S'):
                new_turtle[0] += 1
                traceback = '|'
            elif key == curses.KEY_LEFT or key == ord('a') or key == ord('A'):
                new_turtle[1] -= 1
                traceback = '-'
            elif key == curses.KEY_RIGHT or key == ord('d') or key == ord('D'):
                new_turtle[1] += 1
                traceback = '-'
            #Diagonal cima-direita
            elif key == ord('e') or key == ('E'):
                new_turtle[0] -= 1 
                new_turtle[1] += 1
                traceback = '/'
            #Diagonal cima-esquerda
            elif key == ord('q') or key == ('Q'):
                new_turtle[0] -= 1 
                new_turtle[1] -= 1
                traceback = '\\'
            #Diagonal baixo-esquerda
            elif key == ord('z') or key == ('Z'):
                new_turtle[0] += 1
                new_turtle[1] -= 1
                traceback = '/'
            #Diagonal baixo-direita
            elif key == ord('c') or key == ('C'):
                new_turtle[0] += 1
                new_turtle[1] += 1
                traceback = '\\'
            else:
                continue

            # Movimentação dentro da tela
            if new_turtle[0] < 0 or new_turtle[0] >= sh or new_turtle[1] < 0 or new_turtle[1] >= sw:
                break

            # Desenho
            if pen_down:
                w.addch(turtle[0], turtle[1], traceback)
            else:
                w.addch(turtle[0], turtle[1], ' ')

            # Nova posição
            w.addch(new_turtle[0], new_turtle[1], '@')
            w.refresh()
            turtle = new_turtle
#curses.wrapper(main)


