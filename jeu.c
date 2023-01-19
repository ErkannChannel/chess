#include <stdio.h>
#include "include/struct.h"
#include "src/print_board.c"
#include "src/print_move.c"




void ajouterDeplacementPion(int x, int y, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]) {
    if (board[x][y].couleur == 1) {
        if (x > 0) {
            deplacements[*nombreDeplacements].xDepart = x;
            deplacements[*nombreDeplacements].yDepart = y;
            deplacements[*nombreDeplacements].xArrivee = x - 1;
            deplacements[*nombreDeplacements].yArrivee = y;
            (*nombreDeplacements)++;
            if (x == 6) {
                deplacements[*nombreDeplacements].xDepart = x;
                deplacements[*nombreDeplacements].yDepart = y;
                deplacements[*nombreDeplacements].xArrivee = x - 2;
                deplacements[*nombreDeplacements].yArrivee = y;
                (*nombreDeplacements)++;
            }
        }
    } else if (board[x][y].couleur == 0) {
        if (x < 7) {
            deplacements[*nombreDeplacements].xDepart = x;
            deplacements[*nombreDeplacements].yDepart = y;
	    deplacements[*nombreDeplacements].xArrivee = x + 1;
	    deplacements[*nombreDeplacements].yArrivee = y;
	    (*nombreDeplacements)++;
	    if (x == 1) {
		deplacements[*nombreDeplacements].xDepart = x;
		deplacements[*nombreDeplacements].yDepart = y;
		deplacements[*nombreDeplacements].xArrivee = x + 2;
		deplacements[*nombreDeplacements].yArrivee = y;
		(*nombreDeplacements)++;
	    }
	}
    }
}



int main() {

    struct Piece board[8][8];

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(i == 1) {
                board[i][j].type = PION;
		board[i][j].name = 'P';
                board[i][j].couleur = 0;
            } else if(i == 6) {
                board[i][j].type = PION;
		board[i][j].name = 'P';
                board[i][j].couleur = 1;
	    } else if(i == 7 && (j == 0 || j == 7)) {
                board[i][j].type = TOUR;
                board[i][j].name = 'T';
                board[i][j].couleur = 1;
	    } else if(i == 0 && (j == 0 || j == 7)) {
                board[i][j].type = TOUR;
                board[i][j].name = 'T';
                board[i][j].couleur = 0;
            } else if(i == 0 && (j == 1 || j == 6)) {
                board[i][j].type = CAVALIER;
                board[i][j].name = 'C';
                board[i][j].couleur = 0;
            } else if(i == 7 && (j == 1 || j == 6)) {
                board[i][j].type = CAVALIER;
                board[i][j].name = 'C';
                board[i][j].couleur = 1;
            } else if(i == 0 && (j == 2 || j == 5)) {
                board[i][j].type = FOU;
                board[i][j].name = 'F';
                board[i][j].couleur = 0;
            } else if(i == 7 && (j == 2 || j == 5)) {
                board[i][j].type = FOU;
                board[i][j].name = 'F';
                board[i][j].couleur = 1;
            } else if(i == 0 && j == 3) {
                board[i][j].type = REINE;
                board[i][j].name = 'D';
                board[i][j].couleur = 0;
            } else if(i == 7 && j == 3) {
                board[i][j].type = REINE;
                board[i][j].name = 'D';
                board[i][j].couleur = 1;
            } else if(i == 0 && j == 4) {
                board[i][j].type = ROI;
                board[i][j].name = 'R';
                board[i][j].couleur = 0;
            } else if(i == 7 && j == 4) {
                board[i][j].type = ROI;
                board[i][j].name = 'R';
                board[i][j].couleur = 1;
            } else {
                board[i][j].type = PAS_DE_PIECE;
		board[i][j].name = ' ';

            }
        }
    }
    affichePlateau(board);
    int nombreDeplacements = 0;
    struct Deplacement deplacements[50];
    ajouterDeplacementPion(1, 0, deplacements, &nombreDeplacements,board);
    ajouterDeplacementPion(1, 1, deplacements, &nombreDeplacements,board);
    ajouterDeplacementPion(1, 2, deplacements, &nombreDeplacements,board);

    afficheDeplacements(deplacements,nombreDeplacements);
    

    return 0;
}
