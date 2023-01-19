#ifndef STRUCT_H
#define STRUCT_H

enum PieceType {
    PION,
    CAVALIER,
    FOU,
    TOUR,
    REINE,
    ROI,
    PAS_DE_PIECE
};

struct Piece {
    enum PieceType type; // type de la pièce
    int couleur; // couleur de la pièce (0 pour blanc ou 1 pour noir)
    int x, y; // position actuelle de la pièce sur le plateau
    char name; // temporaire, pour l'affichage.
};


struct Deplacement {
    int xDepart; // position x de départ
    int yDepart; // position y de départ
    int xArrivee; // position x d'arrivée
    int yArrivee; // position y d'arrivée
};


#endif
