CC = gcc
CFLAGS = -Wall -Wextra -g

SRC2 = lucas.c

jeu: ${OBJ}

.PHONY: clean

lucas:
	${CC} -o lucas -pthread -Wall -Wextra ${SRC2} -lSDL2 -lSDL2_image -lSDL2_ttf

clean:
	${RM} lucas
