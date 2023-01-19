#include <stdio.h>
#include "../include/struct.h"
#include "../include/print_move.h"


void afficheDeplacements(struct Deplacement* deplacements, int nbDeplacements) {
    for (int i = 0; i < nbDeplacements; i++)
        printf("Deplacement %d: %c%d -> %c%d\n", i+1, 'a' + deplacements[i].yDepart, 8 - deplacements[i].xDepart, 'a' + deplacements[i].yArrivee, 8 - deplacements[i].xArrivee);
}
