#include <SDL2/SDL.h>
#include <stdbool.h>
#include "SDL2/SDL_image.h"
#include "../include/struct.h"
#include <SDL2/SDL_ttf.h>

#define BOARD_SIZE 8
#define TILE_SIZE 64

void display_first_screen(SDL_Renderer* renderer){


  SDL_SetRenderDrawColor(renderer, 0x3d, 0x3a, 0x38, 0xFF);
  SDL_Rect dst = {0, 0, 700, 512};
  SDL_RenderFillRect(renderer, &dst);
  SDL_SetRenderDrawColor(renderer, 0x80, 0xa4, 0x64, 0xFF);

  SDL_Surface* logo_surface = IMG_Load("pieces/logo.png");
      if (logo_surface == NULL)
          printf("Error loading image: %s\n", SDL_GetError());
  SDL_Texture* piece_texture = SDL_CreateTextureFromSurface(renderer, logo_surface);
  SDL_Rect dst25 = { 222, -10, 250, 250 };
  SDL_RenderCopy(renderer, piece_texture, NULL, &dst25);
  SDL_DestroyTexture(piece_texture);

  SDL_Rect tfp1 = {150, 400, 400, 87};
  SDL_RenderFillRect(renderer, &tfp1);
  SDL_Rect tfp2 = {150, 300, 400, 87};
  SDL_RenderFillRect(renderer, &tfp2);
  SDL_Rect tfp3 = {150, 200, 400, 87};
  SDL_RenderFillRect(renderer, &tfp3);
  // Initialize TTF library
  if (TTF_Init() == -1)
      printf("Error initializing TTF: %s\n", TTF_GetError());

  // Load font
  TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 10);
  if (!font)
      printf("Error loading font: %s\n", TTF_GetError());

  // Render text to surface
  char text1[] = "    IA VS IA    ";
  char text2[] = "  Joueur VS IA  ";
  char text3[] = "Joueur VS Joueur";
  SDL_Color color;
  color = (SDL_Color){238, 238, 210};

  SDL_Surface *surface1 = TTF_RenderText_Solid(font, text1, color);
  if (!surface1)
      printf("Error rendering text: %s\n", TTF_GetError());
  SDL_Surface *surface2 = TTF_RenderText_Solid(font, text2, color);
  if (!surface2)
      printf("Error rendering text: %s\n", TTF_GetError());
  SDL_Surface *surface3 = TTF_RenderText_Solid(font, text3, color);
  if (!surface3)
      printf("Error rendering text: %s\n", TTF_GetError());

  // Convert surface to texture
  SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
  if (!texture1)
      printf("Error creating texture from surface: %s\n", SDL_GetError());
  SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
  if (!texture2)
      printf("Error creating texture from surface: %s\n", SDL_GetError());
  SDL_Texture *texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
  if (!texture3)
      printf("Error creating texture from surface: %s\n", SDL_GetError());

  // Set destination rectangle for the text
  SDL_Rect dest1 = {245, 230 , 200, 30};
  SDL_Rect dest2 = {245, 330 , 200, 30};
  SDL_Rect dest3 = {245, 430 , 200, 30};

  // Render the text
  SDL_RenderCopy(renderer, texture1, NULL, &dest1);
  SDL_RenderCopy(renderer, texture2, NULL, &dest2);
  SDL_RenderCopy(renderer, texture3, NULL, &dest3);

  // Clean up
  TTF_CloseFont(font);
  TTF_Quit();
}

/*
void display_dead_piece(SDL_Renderer* renderer, int* dead_piece, int color, SDL_Surface* white_pion_surface,SDL_Surface* white_cavalier_surface,SDL_Surface* white_fou_surface,SDL_Surface* white_rook_surface,SDL_Surface* white_king_surface,SDL_Surface* white_queen_surface,SDL_Surface* black_pion_surface,SDL_Surface* black_fou_surface, SDL_Surface* black_cavalier_surface,SDL_Surface* black_rook_surface,SDL_Surface* black_king_surface, SDL_Surface* black_queen_surface){
  for(int i = 0; i<sizeof(dead_piece); i++)
    for(int x = 0; x<dead_piece[i]; x++){
      SDL_Rect dst = { 520, 20, 50, 50};
      SDL_Surface* piece = NULL;
      if(color == 0)
          if(i == PION)
            piece = black_pion_surface;
          else if(i == CAVALIER)
            piece = black_cavalier_surface;
          else if(i == FOU)
            piece = black_fou_surface;
          else if(i == TOUR)
            piece = black_rook_surface;
          else if(i == DAME)
            piece = piece = black_queen_surface;
          else if(i == ROI)
            black_king_surface;
          else
            continue;
      else
        if(i == PION)
          piece = white_pion_surface;
        else if(i == CAVALIER)
          piece = white_cavalier_surface;
        else if(i == FOU)
          piece = white_fou_surface;
        else if(i == TOUR)
          piece = white_rook_surface;
        else if(i == DAME)
          piece = white_queen_surface;
        else if(i == ROI)
          piece = white_king_surface;
        else
          continue;
      SDL_Texture* piece_texture = SDL_CreateTextureFromSurface(renderer, piece);
      SDL_RenderCopy(renderer, piece_texture, NULL, &dst);
      SDL_DestroyTexture(piece_texture);
    }
}
*/

void display_end_screen(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0x3d, 0x3a, 0x38, 0xFF);
  SDL_Rect dst = {200, 24, 300, 463};
  SDL_RenderFillRect(renderer, &dst);
}


void display_menu(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0x27, 0x24, 0x22, 0xFF);
  SDL_Rect dst = {512, 0, 188, 512};
  SDL_RenderFillRect(renderer, &dst);
}


void display_piece(SDL_Renderer* renderer, SDL_Surface* piece, int x, int y){
  int posX = x * TILE_SIZE;
  int posY = y * TILE_SIZE;

  SDL_Texture* piece_texture = SDL_CreateTextureFromSurface(renderer, piece);

  SDL_Rect dst = { posX, posY, TILE_SIZE, TILE_SIZE };

  SDL_RenderCopy(renderer, piece_texture, NULL, &dst);
  SDL_DestroyTexture(piece_texture);
}



void display_piece_to_play(enum PieceType piece, int couleur,SDL_Renderer* renderer, int x, int y, SDL_Surface* white_pion_surface,SDL_Surface* white_cavalier_surface,SDL_Surface* white_fou_surface,SDL_Surface* white_rook_surface,SDL_Surface* white_king_surface,SDL_Surface* white_queen_surface,SDL_Surface* black_pion_surface,SDL_Surface* black_fou_surface, SDL_Surface* black_cavalier_surface,SDL_Surface* black_rook_surface,SDL_Surface* black_king_surface, SDL_Surface* black_queen_surface){
  SDL_SetRenderDrawColor(renderer, 0xEE, 0xEE, 0x00, 0xFF);
  SDL_Rect dst = { x*TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE };
  SDL_RenderFillRect(renderer, &dst);
  if(couleur == 0)
    if(piece == PION)
      display_piece(renderer, black_pion_surface, x, y);
    else if(piece == CAVALIER)
      display_piece(renderer, black_cavalier_surface, x, y);
    else if(piece == FOU)
      display_piece(renderer, black_fou_surface, x, y);
    else if(piece == TOUR)
      display_piece(renderer, black_rook_surface, x, y);
    else if(piece == DAME)
      display_piece(renderer, black_queen_surface, x, y);
    else if(piece == ROI)
      display_piece(renderer, black_king_surface, x, y);
    else
      printf("");
  else
    if(piece == PION)
      display_piece(renderer, white_pion_surface, x, y);
    else if(piece == CAVALIER)
      display_piece(renderer, white_cavalier_surface, x, y);
    else if(piece == FOU)
      display_piece(renderer, white_fou_surface, x, y);
    else if(piece == TOUR)
      display_piece(renderer, white_rook_surface, x, y);
    else if(piece == DAME)
      display_piece(renderer, white_queen_surface, x, y);
    else if(piece == ROI)
      display_piece(renderer, white_king_surface, x, y);
    else
      printf("");
}




void display_ttf(SDL_Renderer* renderer, int x, int y){
  if(y == 0 || x == 0){
    // Initialize TTF library
    if (TTF_Init() == -1)
        printf("Error initializing TTF: %s\n", TTF_GetError());

    // Load font
    TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 1000);
    if (!font)
        printf("Error loading font: %s\n", TTF_GetError());

    // Render text to surface
    char text[2];
    SDL_Color color;
    if(y == 0){
      if(x%2 == 1)
        color = (SDL_Color){238, 238, 210};
      else
        color = (SDL_Color){118, 150, 86};
      sprintf(text, "%d", x+1);
    }
    else{
      if(y%2 == 1)
        color = (SDL_Color){238, 238, 210};
      else
        color = (SDL_Color){118, 150, 86};
      sprintf(text, "%d", y+1);
    }

    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    if (!surface)
        printf("Error rendering text: %s\n", TTF_GetError());

    // Convert surface to texture
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture)
        printf("Error creating texture from surface: %s\n", SDL_GetError());
    // Set destination rectangle for the text
    SDL_Rect dest = {x* TILE_SIZE, y * TILE_SIZE , 13, 13};

    // Render the text
    SDL_RenderCopy(renderer, texture, NULL, &dest);

    // Clean up
    TTF_CloseFont(font);
    TTF_Quit();
  }
}

void draw_board(SDL_Renderer* renderer, struct Piece board[8][8], SDL_Surface* white_pion_surface,SDL_Surface* white_cavalier_surface,SDL_Surface* white_fou_surface,SDL_Surface* white_rook_surface,SDL_Surface* white_king_surface,SDL_Surface* white_queen_surface,SDL_Surface* black_pion_surface,SDL_Surface* black_fou_surface, SDL_Surface* black_cavalier_surface,SDL_Surface* black_rook_surface,SDL_Surface* black_king_surface, SDL_Surface* black_queen_surface){
  for (int x = 0; x < BOARD_SIZE; x++)
    for (int y = 0; y < BOARD_SIZE; y++){
      if ((x + y) % 2 == 0)
        SDL_SetRenderDrawColor(renderer, 0xEE, 0xEE, 0xD2, 0xFF);
      else
        SDL_SetRenderDrawColor(renderer, 0x76, 0x96, 0x56, 0xFF);
      display_ttf(renderer, x, y);
      SDL_Rect rect = { y * TILE_SIZE, x * TILE_SIZE, TILE_SIZE, TILE_SIZE };
      SDL_RenderFillRect(renderer, &rect);
      if(board[x][y].couleur == 0)
        if(board[x][y].type == PION)
          display_piece(renderer, black_pion_surface, y, x);
        else if(board[x][y].type == CAVALIER)
          display_piece(renderer, black_cavalier_surface, y, x);
        else if(board[x][y].type == FOU)
          display_piece(renderer, black_fou_surface, y, x);
        else if(board[x][y].type == TOUR)
          display_piece(renderer, black_rook_surface, y, x);
        else if(board[x][y].type == DAME)
          display_piece(renderer, black_queen_surface, y, x);
        else if(board[x][y].type == ROI)
          display_piece(renderer, black_king_surface, y, x);
        else
          continue;
      else
        if(board[x][y].type == PION)
          display_piece(renderer, white_pion_surface, y, x);
        else if(board[x][y].type == CAVALIER)
          display_piece(renderer, white_cavalier_surface, y, x);
        else if(board[x][y].type == FOU)
          display_piece(renderer, white_fou_surface, y, x);
        else if(board[x][y].type == TOUR)
          display_piece(renderer, white_rook_surface, y, x);
        else if(board[x][y].type == DAME)
          display_piece(renderer, white_queen_surface, y, x);
        else if(board[x][y].type == ROI)
          display_piece(renderer, white_king_surface, y, x);
        else
          continue;
	}
}
