TARGET = Menu
LIBSC = src/lib/pdcurses.a
INCLUDE = src/include

SRCS = src/turtle_functions.c
MAIN_SRC1 = src/Logo_Turtle_Imput.c
MAIN_SRC2 = src/Logo_Turtle_Keyboard.c 
MENU_SRC = menu.c

CXX = gcc
FLAGS = -I${INCLUDE}

default:
	$(CXX) ${FLAGS} ${MENU_SRC} ${SRCS} ${MAIN_SRC1} ${MAIN_SRC2} $(LIBSC) -o ${TARGET}.exe
