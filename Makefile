CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = jeu.c
OBJ = ${SRC:.c=.o}

jeu: ${OBJ}

.PHONY: clean

clean:
	${RM} jeu jeu.o
