#include <stdio.h>
#include "../include/struct.h"
#include "../include/print_board.h"

void affichePlateau(struct Piece plateau[8][8]) {
  printf("   A B C D E F G H\n");        // Affiche les lettres de colonne en haut de l'échiquier
  for(int i = 0; i < 8; i++) {           // Boucle pour parcourir toutes les lignes de l'échiquier
    printf(" %d ", 8-i);                 // Affiche le numéro de la ligne avant de parcourir les colonnes
    for(int j = 0; j < 8; j++)           // Boucle pour parcourir toutes les colonnes de l'échiquier
      if(plateau[i][j].name != ' ')      // Si la case actuelle contient une pièce
	if (plateau[i][j].couleur == 0)  // Si la pièce est blanche, affiche son nom en majuscule
	  printf("%c ", plateau[i][j].name);
	else                             // Sinon, affiche son nom en minuscule pour indiquer qu'il s'agit d'une pièce noire
	  printf("%c ", tolower(plateau[i][j].name));
      else                               // Si la case actuelle est vide, affiche un point
	printf(". ");
    printf(" %d\n", 8-i);                // Affiche le numéro de la ligne après avoir parcouru les colonnes
  }
  printf("   A B C D E F G H\n");        // Affiche les lettres de colonne en bas de l'échiquier
}
