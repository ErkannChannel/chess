CC = gcc
CFLAGS = -Wall -Wextra -g -lSDL2 -lSDL2_image

SRC = jeu.c
OBJ = ${SRC:.c=.o}

jeu: ${OBJ}

.PHONY: clean

video:
	${CC} -o game ${SRC} -lSDL2 -lSDL2_image -lSDL2_ttf

clean:
	${RM} jeu jeu.o
