TARGET = Turtle.imput
LIBSC = lib\pdcurses.a
INCLUDE = include

SRC = turtle.imput.c

# Opcoes de compiladores
CXX = gcc
FLAGS = -I${INCLUDE}

default:
	$(CXX) ${FLAGS} ${SRC}  $(LIBSC) -o ${TARGET}

