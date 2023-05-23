CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf


SRC2 = src/lucas.c
SRC = include/gui.h include/print_board.h include/lucas.h

jeu: ${OBJ}

.PHONY: clean

lucas:
	${CC} -o lucas ${SRC2} ${SRC} ${CFLAGS} ${LDFLAGS}

clean:
	${RM} lucas
