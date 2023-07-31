TARGET = Turtle_imput
LIBSC = lib\pdcurses.a
INCLUDE = include

SRC = Turtle_imput.c

# Opcoes de compiladores
CXX = gcc
FLAGS = -I${INCLUDE}

default:
	$(CXX) ${FLAGS} ${SRC}  $(LIBSC) -o ${TARGET}.exe
