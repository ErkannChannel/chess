#ifndef LUCAS_H
#define LUCAS_H

#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "struct.h"
#include "gui.h"
#include "print_board.h"


#define MAX_LINE_LENGTH 1024
#define MAX_MOVES_PER_LINE 256
#define MAX_MOVES_HISTORY 50


int RoiEnEchec_player(int xRoi,int yRoi, int couleur,struct Piece board[8][8],int xRoiEnnemie, int yRoiEnnemie);

int RoiEnEchec_bot(int xRoi,int yRoi,struct Piece board[8][8]);

void ajout_deplacement(int x, int y ,int xArriver, int yArriver,struct Deplacement deplacements[], int* nombreDeplacements );

int case_existe(int x, int y);

int piece_cloue(int x, int y, int xRoi, int yRoi, struct Piece board[8][8]);

void ajouterDeplacementPion(int x, int y, int xRoi, int yRoi, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]);

void ajouterDeplacementCavalier(int x, int y, int xRoi, int yRoi, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]);

void ajouterDeplacementTour(int x, int y, int xRoi, int yRoi, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]);

void ajouterDeplacementFou(int x, int y, int xRoi, int yRoi, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]);

int trouverRoi(int couleur, struct Piece board[8][8]);

void ajouterDeplacementRoi(int x, int y, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]);

void ajouterDeplacementDame(int x, int y, int xRoi, int yRoi, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]);

void __interception(int i, int j,int x, int y, int xRoi, int yRoi,struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8] );

void interception(int x,int y,int xRoi, int yRoi,struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8],int couleur);

void interception_global(int xMenace, int yMenace, int xRoi, int yRoi,struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8],int couleur);

void ajouterDeplacementsPossibles( int couleur, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]);

void initialiserPlateau(struct Piece plateau[8][8], char* fen);

void roi_mange_menace(int xmenace,int ymenace,int xRoi,int yRoi,struct Deplacement* deplacements,int* nbDeplacements,struct Piece board[8][8],int couleur );

void deplacementsPossibles(int couleur,struct Deplacement* deplacements, int* nbDeplacements,  struct Piece board[8][8] );

int estPresent(struct Deplacement deplacement, struct Deplacement listeDeplacements[], int n);

void mettre_la_case_a_vide(int x,int y,struct Piece board[8][8]);

void movePiece(struct Deplacement deplacement, struct Piece board[8][8], int couleur);

void position_precedante(struct Piece board[8][8],struct Piece manger,struct Piece deplacer,struct Deplacement deplacement);

struct ThreadArgs {
    int tours_restant;
    int couleur;
    int IA_Couleur;
    struct Piece board[8][8];
    float result;
};

float fmin2(float a, float b);

float fmax2(float a, float b);

int inverse(int couleur);

void copy_board(struct Piece dest[8][8], struct Piece src[8][8]);

float protege_par_pion(struct Piece board[8][8],int x, int y, int couleur);

float calculer_position_pion(struct Piece board[8][8],int x, int y, int couleur);

float calculer_position_cavalier(int x, int y);

float calculer_position_tour(struct Piece board[8][8],int x, int y, int couleur);

float calculer_position_fou(struct Piece board[8][8],int x, int y, int couleur);

float calculer_position_roi(struct Piece board[8][8],int x, int y, int couleur);

float calculer_score(struct Piece board[8][8], int joueur);

float calculer_score_V2(struct Piece board[8][8], int joueur);

float minmax_ancien(int tours_restant, int couleur,int IA_Couleur, struct Piece board[8][8]);

float alphabeta(int tours_restants, int PROFONDEUR_ATTENTE, int couleur, int IA_Couleur, struct Piece board[8][8], float alpha, float beta);

float minmax(int tours_restants,int PROFONDEUR_ATTENTE, int couleur, int IA_Couleur, struct Piece board[8][8]);

float minmax2(int tours_restant, int couleur,int IA_Couleur, struct Piece board[8][8]);

void minmax_intermediaire(int couleur, int IA_Couleur, struct Piece board[8][8], float* rep);

void* threadFunc(void* args);

struct Deplacement main_minmax(int tours_restant, int couleur, struct Piece board[8][8]);

struct Deplacement main_minmax_ancien(int tours_restant, int couleur, struct Piece board[8][8]);

struct Deplacement conversionString(char* str, struct Piece board[8][8]);

struct Deplacement ouverture_bot(struct Deplacement argv[], int* nb_deplacements, struct Piece board[8][8]);

int transcription(int x);

void play(SDL_Window *window, int mode, int difficulty_bot, int theme);

void fun_main(SDL_Window* window, int theme);

void test();

void test2();

void test3();

void test4();

void test_IA_Fen(char fen[],struct Deplacement rep,int temps);

void test_IA_Fen2(char fen[],struct Deplacement rep[],struct Deplacement depl[],int temps,int nbrep);

struct Deplacement ini(int x1,int y1,int x2,int y2);

void test10();

int main();


#endif