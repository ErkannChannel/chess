#include <SDL2/SDL.h>
#include <stdbool.h>
#include "SDL2/SDL_image.h"
#include "../include/struct.h"
#include <SDL2/SDL_ttf.h>

#define BOARD_SIZE 8
#define TILE_SIZE 64


display_piece_to_play(enum PieceType piece,SDL_Renderer* renderer, int x, int y){
  SDL_Rect dst = { x*TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE };
  SDL_SetRenderDrawColor(renderer, 0xEE, 0xEE, 0xD2, 0xFF);
  SDL_RenderFillRect(renderer, &dst);
}
void display_piece(SDL_Renderer* renderer, SDL_Surface* piece, int x, int y)
    {
      int posX = x * TILE_SIZE;
      int posY = y * TILE_SIZE;

      SDL_Texture* piece_texture = SDL_CreateTextureFromSurface(renderer, piece);

      SDL_Rect dst = { posX, posY, TILE_SIZE, TILE_SIZE };

      SDL_RenderCopy(renderer, piece_texture, NULL, &dst);
      SDL_DestroyTexture(piece_texture);
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

void draw_board(SDL_Renderer* renderer, struct Piece board[8][8]){
  SDL_Surface* black_pion_surface = IMG_Load("pieces/black/black_pion.png");
  if (black_pion_surface == NULL)
    printf("Error loading image: %s\n", SDL_GetError());
  SDL_Surface* black_rook_surface = IMG_Load("pieces/black/black_rook.png");
  if (black_rook_surface == NULL)
    printf("Error loading image: %s\n", SDL_GetError());
  SDL_Surface* black_cavalier_surface = IMG_Load("pieces/black/black_cavalier.png");
  if (black_cavalier_surface == NULL)
    printf("Error loading image: %s\n", SDL_GetError());
  SDL_Surface* black_fou_surface = IMG_Load("pieces/black/black_fou.png");
  if (black_fou_surface == NULL)
    printf("Error loading image: %s\n", SDL_GetError());
  SDL_Surface* black_queen_surface = IMG_Load("pieces/black/black_queen.png");
  if (black_queen_surface == NULL)
    printf("Error loading image: %s\n", SDL_GetError());
  SDL_Surface* black_king_surface = IMG_Load("pieces/black/black_king.png");
  if (black_king_surface == NULL)
    printf("Error loading image: %s\n", SDL_GetError());
  SDL_Surface* white_pion_surface = IMG_Load("pieces/white/white_pion.png");
  if (white_pion_surface == NULL)
    printf("Error loading image: %s\n", SDL_GetError());
  SDL_Surface* white_rook_surface = IMG_Load("pieces/white/white_rook.png");
  if (white_rook_surface == NULL)
    printf("Error loading image: %s\n", SDL_GetError());
  SDL_Surface* white_fou_surface = IMG_Load("pieces/white/white_fou.png");
  if (white_fou_surface == NULL)
    printf("Error loading image: %s\n", SDL_GetError());
  SDL_Surface* white_cavalier_surface = IMG_Load("pieces/white/white_cavalier.png");
  if (white_cavalier_surface == NULL)
    printf("Error loading image: %s\n", SDL_GetError());
  SDL_Surface* white_queen_surface = IMG_Load("pieces/white/white_queen.png");
  if (white_queen_surface == NULL)
    printf("Error loading image: %s\n", SDL_GetError());
  SDL_Surface* white_king_surface = IMG_Load("pieces/white/white_king.png");
  if (white_king_surface == NULL)
    printf("Error loading image: %s\n", SDL_GetError());

  for (int x = 0; x < BOARD_SIZE; x++)
    for (int y = 0; y < BOARD_SIZE; y++) {
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
          printf("");
      else if(board[x][y].couleur == 1)
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
          printf("");
      else
        printf("");
	
	}
}
