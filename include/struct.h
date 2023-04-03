#ifndef STRUCT_H
#define STRUCT_H

const int BLANC = 1;
const int NOIR = 0;
const int VIDE = -1;


enum PieceType {
    PION,
    CAVALIER,
    FOU,
    TOUR,
    DAME,
    ROI,
    PAS_DE_PIECE
};

struct Piece {
    enum PieceType type; // type de la pièce
    int couleur; // couleur de la pièce (0 pour blanc ou 1 pour noir)
    char name; // temporaire, pour l'affichage.
    int test_roquable; //  1 quand la piéce peut roquer
};


struct Deplacement {
    int xDepart; // position x de départ
    int yDepart; // position y de départ
    int xArrivee; // position x d'arrivée
    int yArrivee; // position y d'arrivée
};


#endif
