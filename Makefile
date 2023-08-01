TARGET = Logo_Turtle_Imput
LIBSC = lib\pdcurses.a
INCLUDE = include

SRC = Logo_Turtle_Imput.c

# Opcoes de compiladores
CXX = gcc
FLAGS = -I${INCLUDE}

default:
	$(CXX) ${FLAGS} ${SRC}  $(LIBSC) -o ${TARGET}.exe
