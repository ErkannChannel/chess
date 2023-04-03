#include <stdio.h>
#include "../include/struct.h"
#include "../include/print_board.h"

#define couleur(param) printf("\033[%sm",param)

void affichePlateau(struct Piece plateau[8][8]) {
    // Affiche les lettres de colonne en haut de l'échiquier
    printf("   A B C D E F G H\n");
    // Boucle pour parcourir toutes les lignes de l'échiquier
    for(int i = 0; i < 8; i++) {
        // Affiche le numéro de la ligne avant de parcourir les colonnes
        printf(" %d ", 8-i);
        // Boucle pour parcourir toutes les colonnes de l'échiquier
        for(int j = 0; j < 8; j++) {
            // Si la case actuelle contient une pièce
            if(plateau[i][j].name != ' ') {
                // Si la pièce est blanche, affiche son nom en majuscule
                if (plateau[i][j].couleur == 0) {
                    couleur("36");
                    printf("%c ", tolower(plateau[i][j].name));
                    couleur("0");
                } else {
                    // Sinon, affiche son nom en minuscule pour indiquer qu'il s'agit d'une pièce noire
                    couleur("31");
                    printf("%c ", plateau[i][j].name);
                    couleur("0");
                }
            } else {
                // Si la case actuelle est vide, affiche un point
                printf(". ");
            }
        }
        // Affiche le numéro de la ligne après avoir parcouru les colonnes
        printf(" %d\n", 8-i);
    }
    // Affiche les lettres de colonne en bas de l'échiquier
    printf("   A B C D E F G H\n");
}
