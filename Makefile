TARGET = Logo_Turtle_Imput
LIBSC = lib\pdcurses.a
INCLUDE = include

# Lista de arquivos fonte em src/
SRCS = src/turtle_functions.c
MAIN_SRC = Logo_Turtle_Imput.c

# Opcoes de compiladores
CXX = gcc
FLAGS = -I${INCLUDE}

default:
	$(CXX) ${FLAGS} ${MAIN_SRC} ${SRCS} $(LIBSC) -o ${TARGET}.exe