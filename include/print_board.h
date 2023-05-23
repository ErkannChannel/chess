#ifndef PRINT_BOARD_H
#define PRINT_BOARD_H
#include "struct.h"
#include <ctype.h>
#include <stdio.h>

#define couleur(param) printf("\033[%sm",param)


void affichePlateau(struct Piece plateau[8][8]);

#endif
