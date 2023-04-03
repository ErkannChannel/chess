CC = gcc
CFLAGS = -Wall -Wextra -g

SRC1 = damien.c
SRC2 = lucas.c
SRC3 = Bot/try.py

jeu: ${OBJ}

.PHONY: clean

timothee:
	${CC} -o timothee ${SRC1}

lucas:
	${CC} -o lucas ${SRC2} -lSDL2 -lSDL2_image -lSDL2_ttf

clean:
	${RM} jeu jeu.o lucas damien timothee
