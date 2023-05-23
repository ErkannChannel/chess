#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "SDL2/SDL_image.h"
#include "../include/struct.h"
#include <SDL2/SDL_ttf.h>

#define BOARD_SIZE 8
#define TILE_SIZE 123

void display_first_screen(SDL_Renderer* renderer);

void player(SDL_Renderer* renderer);

void display_whoplay(SDL_Renderer* renderer, int color);

void display_end_screen(SDL_Renderer* renderer);

void display_move(int X, int Y, struct Deplacement* deplacements, int nbDeplacements, SDL_Renderer* renderer);

void display_choose_difficulty(SDL_Renderer* renderer);

void display_menu(SDL_Renderer* renderer);

void display_piece(SDL_Renderer* renderer, SDL_Surface* piece, int x, int y);

void display_piece_to_play(enum PieceType piece, int couleur,SDL_Renderer* renderer, int x, int y, SDL_Surface* white_pion_surface,SDL_Surface* white_cavalier_surface,SDL_Surface* white_fou_surface,SDL_Surface* white_rook_surface,SDL_Surface* white_king_surface,SDL_Surface* white_queen_surface,SDL_Surface* black_pion_surface,SDL_Surface* black_fou_surface, SDL_Surface* black_cavalier_surface,SDL_Surface* black_rook_surface,SDL_Surface* black_king_surface, SDL_Surface* black_queen_surface);

void display_ttf(SDL_Renderer* renderer, int x, int y);

void draw_board(int theme, SDL_Renderer* renderer, struct Piece board[8][8], SDL_Surface* white_pion_surface,SDL_Surface* white_cavalier_surface,SDL_Surface* white_fou_surface,SDL_Surface* white_rook_surface,SDL_Surface* white_king_surface,SDL_Surface* white_queen_surface,SDL_Surface* black_pion_surface,SDL_Surface* black_fou_surface, SDL_Surface* black_cavalier_surface,SDL_Surface* black_rook_surface,SDL_Surface* black_king_surface, SDL_Surface* black_queen_surface);

void draw_board_fourth(SDL_Renderer* renderer);

void piece_fourth(SDL_Renderer* renderer,SDL_Surface* white_pion_surface,SDL_Surface* white_cavalier_surface,SDL_Surface* white_fou_surface,SDL_Surface* white_rook_surface,SDL_Surface* white_king_surface,SDL_Surface* white_queen_surface,SDL_Surface* black_pion_surface,SDL_Surface* black_fou_surface, SDL_Surface* black_cavalier_surface,SDL_Surface* black_rook_surface,SDL_Surface* black_king_surface, SDL_Surface* black_queen_surface);

void display_score(SDL_Renderer* renderer, int score);

#endif
