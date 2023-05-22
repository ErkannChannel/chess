#include <SDL2/SDL.h>
#include <stdbool.h>
#include "SDL2/SDL_image.h"
#include "../include/struct.h"
#include <SDL2/SDL_ttf.h>

#define BOARD_SIZE 8
#define TILE_SIZE 123

void display_first_screen(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0x3d, 0x3a, 0x38, 0xFF);
  SDL_Rect dst = {0, 0, 1500, 980};
  SDL_RenderFillRect(renderer, &dst);
  SDL_SetRenderDrawColor(renderer, 0x80, 0xa4, 0x64, 0xFF);
  SDL_Rect tfp1 = {450, 750, 600, 187};
  SDL_RenderFillRect(renderer, &tfp1);
  SDL_Rect tfp2 = {450, 550, 600, 187};
  SDL_RenderFillRect(renderer, &tfp2);
  SDL_Rect tfp3 = {450, 350, 600, 187};
  SDL_RenderFillRect(renderer, &tfp3);

  SDL_SetRenderDrawColor(renderer, 0xeb, 0x61, 0x50, 0xFF);
  SDL_Rect tfp0 = {200, 750, 200, 200};
  SDL_RenderFillRect(renderer, &tfp0);
  // Initialize TTF library
  if (TTF_Init() == -1)
      printf("Error initializing TTF: %s\n", TTF_GetError());

  // Load font
  TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 10);
  if (!font)
      printf("Error loading font: %s\n", TTF_GetError());

  // Render text to surface
  char text3[] = "    IA VS IA    ";
  char text2[] = "  Joueur VS IA  ";
  char text1[] = "Joueur VS Joueur";
  char text0[] = " Bac à Sable";
  char text4[] = "     CHESS      ";
  SDL_Color color;
  color = (SDL_Color){238, 238, 210};

  SDL_Surface *surface0 = TTF_RenderText_Solid(font, text0, color);
  if (!surface0)
      printf("Error rendering text: %s\n", TTF_GetError());
  SDL_Surface *surface1 = TTF_RenderText_Solid(font, text1, color);
  if (!surface1)
      printf("Error rendering text: %s\n", TTF_GetError());
  SDL_Surface *surface2 = TTF_RenderText_Solid(font, text2, color);
  if (!surface2)
      printf("Error rendering text: %s\n", TTF_GetError());
  SDL_Surface *surface3 = TTF_RenderText_Solid(font, text3, color);
  if (!surface3)
      printf("Error rendering text: %s\n", TTF_GetError());
  SDL_Surface *surface4 = TTF_RenderText_Solid(font, text4, color);
  if (!surface3)
      printf("Error rendering text: %s\n", TTF_GetError());

  // Convert surface to texture
  SDL_Texture *texture0 = SDL_CreateTextureFromSurface(renderer, surface0);
  if (!texture0)
      printf("Error creating texture from surface: %s\n", SDL_GetError());
  SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
  if (!texture1)
      printf("Error creating texture from surface: %s\n", SDL_GetError());
  SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
  if (!texture2)
      printf("Error creating texture from surface: %s\n", SDL_GetError());
  SDL_Texture *texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
  if (!texture3)
      printf("Error creating texture from surface: %s\n", SDL_GetError());
  SDL_Texture *texture4 = SDL_CreateTextureFromSurface(renderer, surface4);
  if (!texture4)
      printf("Error creating texture from surface: %s\n", SDL_GetError());


  // Set destination rectangle for the text
  SDL_Rect dest1 = {475, 800, 550, 90};
  SDL_Rect dest2 = {475, 600, 550, 90};
  SDL_Rect dest3 = {475, 400, 550, 90};
  SDL_Rect dest0 = {200, 810, 200, 45};
  SDL_Rect dest4 = {270, 100, 1000, 200};

  // Render the text
  SDL_RenderCopy(renderer, texture0, NULL, &dest0);
  SDL_RenderCopy(renderer, texture1, NULL, &dest1);
  SDL_RenderCopy(renderer, texture2, NULL, &dest2);
  SDL_RenderCopy(renderer, texture3, NULL, &dest3);
  SDL_RenderCopy(renderer, texture4, NULL, &dest4);

  SDL_FreeSurface(surface1);
  SDL_FreeSurface(surface2);
  SDL_FreeSurface(surface3);
  SDL_FreeSurface(surface4);

  SDL_DestroyTexture(texture1);
  SDL_DestroyTexture(texture2);
  SDL_DestroyTexture(texture3);
  SDL_DestroyTexture(texture4);

  // Clean up
  TTF_CloseFont(font);
  TTF_Quit();
}

/*
void display_dead_piece(struct Piece result[], struct Piece board[8][8], SDL_Renderer* renderer, int color, SDL_Surface* white_pion_surface,SDL_Surface* white_cavalier_surface,SDL_Surface* white_fou_surface,SDL_Surface* white_rook_surface,SDL_Surface* white_king_surface,SDL_Surface* white_queen_surface,SDL_Surface* black_pion_surface,SDL_Surface* black_fou_surface, SDL_Surface* black_cavalier_surface,SDL_Surface* black_rook_surface,SDL_Surface* black_king_surface, SDL_Surface* black_queen_surface){
  for(int i = 0; i<25; i++){
    if(result[i].type == CAVALIER)
      display_piece(renderer, black_pion_surface, 7, 9);
    else if(result[i].type == FOU)
      display_piece(renderer, black_cavalier_surface, 7, 9);
    else if(result[i].type == TOUR)
      display_piece(renderer, black_fou_surface,7, 9);
    else if(result[i].type == DAME)
      display_piece(renderer, black_rook_surface, 7, 9);
  }
}
*/

void timer(SDL_Window* window,  SDL_Renderer* renderer){
  SDL_Event event;
  int running = 1;
  SDL_Color textColor = {255, 255, 255, 0};

  TTF_Font* font = TTF_OpenFont("fonts/arial.ttf", 24);
    if(font == NULL) {
        printf("Font could not be loaded! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

  // Create a surface and texture for the text
  SDL_Surface* textSurface = NULL;
  SDL_Texture* textTexture = NULL;
  char text[20] = "";

  // Initialize timer variables
  Uint32 startTime = 0;
  Uint32 currentTime = 0;
  Uint32 elapsedTime = 0;
  int seconds = 0;

  startTime = SDL_GetTicks();

  while(running) {
      while(SDL_PollEvent(&event))
          if(event.type == SDL_QUIT)
              running = 0;

      // Calculate elapsed time
      currentTime = SDL_GetTicks();
      elapsedTime = currentTime - startTime;
      seconds = elapsedTime / 1000;

      // Render the text to the surface
      sprintf(text, "Seconds: %d", seconds);
      textSurface = TTF_RenderText_Solid(font, text, textColor);

      // Create a texture from the surface
      textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

      // Clear the renderer
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);

      // Render the texture to the screen
      SDL_Rect textRect = {0, 0, textSurface->w, textSurface->h};
      SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

      // Update the screen
      SDL_RenderPresent(renderer);

      // Free the surface and texture
      SDL_FreeSurface(textSurface);
      SDL_DestroyTexture(textTexture);
  }

  // Free the font
  TTF_CloseFont(font);
}


void player(SDL_Renderer* renderer){
  // Initialize TTF library
  if (TTF_Init() == -1)
      printf("Error initializing TTF: %s\n", TTF_GetError());

  // Load font
  TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 10);
  if (!font)
      printf("Error loading font: %s\n", TTF_GetError());

  // Render text to surface
  char text1[] = "    PLayer 1    ";
  char text2[] = "    Player 2    ";
  SDL_Color color;
  color = (SDL_Color){10,10,10};

  SDL_Surface *surface1 = TTF_RenderText_Solid(font, text1, color);
  if (!surface1)
      printf("Error rendering text: %s\n", TTF_GetError());
  SDL_Surface *surface2 = TTF_RenderText_Solid(font, text2, color);
  if (!surface2)
      printf("Error rendering text: %s\n", TTF_GetError());


  // Convert surface to texture
  SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
  if (!texture1)
      printf("Error creating texture from surface: %s\n", SDL_GetError());
  SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
  if (!texture2)
      printf("Error creating texture from surface: %s\n", SDL_GetError());

  // Set destination rectangle for the text
  SDL_Rect dest1 = {1030, 55 , 200, 30};
  SDL_Rect dest2 = {1030, 885 , 200, 30};

  // Render the text
  SDL_RenderCopy(renderer, texture1, NULL, &dest1);
  SDL_RenderCopy(renderer, texture2, NULL, &dest2);

  SDL_FreeSurface(surface1);
  SDL_FreeSurface(surface2);

  SDL_DestroyTexture(texture1);
  SDL_DestroyTexture(texture2);

  // Clean up
  TTF_CloseFont(font);
  TTF_Quit();
}

void display_whoplay(SDL_Renderer* renderer, int color){
  if (color == NOIR){
    SDL_SetRenderDrawColor(renderer, 0x69, 0x69, 0x69, 0xFF);
    SDL_Rect tfp1 = {1020, 860, 250, 87};
    SDL_RenderFillRect(renderer, &tfp1);
    SDL_SetRenderDrawColor(renderer, 0xEE, 0xEE, 0xD2, 0xFF);
    SDL_Rect tfp2 = {1020, 30, 250, 87};
    SDL_RenderFillRect(renderer, &tfp2);
  }
  else{
    SDL_SetRenderDrawColor(renderer, 0xEE, 0xEE, 0xD2, 0xFF);
    SDL_Rect tfp1 = {1020, 860, 250, 87};
    SDL_RenderFillRect(renderer, &tfp1);
    SDL_SetRenderDrawColor(renderer, 0x69, 0x69, 0x69, 0xFF);
    SDL_Rect tfp2 = {1020, 30, 250, 87};
    SDL_RenderFillRect(renderer, &tfp2);
  }
  player(renderer);
}



void display_end_screen(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0x80, 0xa4, 0x64, 0xFF);
  SDL_Rect tfp1 = {1120, 400, 250, 87};
  SDL_RenderFillRect(renderer, &tfp1);
  SDL_Rect tfp2 = {1120, 500, 250, 87};
  SDL_RenderFillRect(renderer, &tfp2);

  // Initialize TTF library
  if (TTF_Init() == -1)
      printf("Error initializing TTF: %s\n", TTF_GetError());

  // Load font
  TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 10);
  if (!font)
      printf("Error loading font: %s\n", TTF_GetError());

  // Render text to surface
  char text1[] = "       End      ";
  char text2[] = "      Retry     ";
  char text3[] = "    Back Menu   ";
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
  SDL_Rect dest1 = {1140, 290 , 200, 30};
  SDL_Rect dest2 = {1140, 430 , 200, 30};
  SDL_Rect dest3 = {1140, 530 , 200, 30};

  // Render the text
  SDL_RenderCopy(renderer, texture1, NULL, &dest1);
  SDL_RenderCopy(renderer, texture2, NULL, &dest2);
  SDL_RenderCopy(renderer, texture3, NULL, &dest3);

  SDL_FreeSurface(surface1);
  SDL_FreeSurface(surface2);
  SDL_FreeSurface(surface3);

  SDL_DestroyTexture(texture1);
  SDL_DestroyTexture(texture2);
  SDL_DestroyTexture(texture3);

  // Clean up
  TTF_CloseFont(font);
  TTF_Quit();
}


void display_move(int X, int Y, struct Piece board[8][8], struct Deplacement* deplacements, int nbDeplacements, SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0x31, 0x2E, 0x2B, 0xFF);
  for (int i = 0; i < nbDeplacements; i++)
      if(deplacements[i].xDepart == X && deplacements[i].yDepart == Y){
      int posX = deplacements[i].yArrivee * TILE_SIZE;
      int posY = deplacements[i].xArrivee * TILE_SIZE;
      SDL_Surface* cross_surface = IMG_Load("pieces/gray_point.png");
      if (cross_surface == NULL)
          printf("Error loading image: %s\n", SDL_GetError());
      SDL_Texture* cross_texture = SDL_CreateTextureFromSurface(renderer, cross_surface);
      SDL_Rect dst25 = { posX+37, posY+37, 50, 50 };
      SDL_RenderCopy(renderer, cross_texture, NULL, &dst25);
      SDL_DestroyTexture(cross_texture);
      SDL_FreeSurface(cross_surface);
    }
}

void display_left_game(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0x31, 0x2E, 0x2B, 0xFF);
  SDL_Rect tfpW = {450, 250, 600, 450};
  SDL_RenderFillRect(renderer, &tfpW);

  SDL_Surface* cross_surface = IMG_Load("pieces/cross.png");
    if (cross_surface == NULL)
        printf("Error loading image: %s\n", SDL_GetError());
  SDL_Texture* cross_texture = SDL_CreateTextureFromSurface(renderer, cross_surface);
  SDL_Rect dst25 = { 1050, 170, 100, 100 };
  SDL_RenderCopy(renderer, cross_texture, NULL, &dst25);
  SDL_DestroyTexture(cross_texture);

  SDL_SetRenderDrawColor(renderer, 0x80, 0xa4, 0x64, 0xFF);
  SDL_Rect tfp1 = {500, 500, 500, 160};
  SDL_RenderFillRect(renderer, &tfp1);





  // Initialize TTF library
  if (TTF_Init() == -1)
      printf("Error initializing TTF: %s\n", TTF_GetError());

  // Load font
  TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 10);
  if (!font)
      printf("Error loading font: %s\n", TTF_GetError());

  // Render text to surface
  char text1[] = "        Menu        ";
  char text2[] = "      Quit Game     ";
  
  SDL_Color color;
  color = (SDL_Color){238, 238, 210};

  SDL_Surface *surface1 = TTF_RenderText_Solid(font, text1, color);
  if (!surface1)
      printf("Error rendering text: %s\n", TTF_GetError());
  SDL_Surface *surface2 = TTF_RenderText_Solid(font, text2, color);
  if (!surface2)
      printf("Error rendering text: %s\n", TTF_GetError());


  // Convert surface to texture
  SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
  if (!texture1)
      printf("Error creating texture from surface: %s\n", SDL_GetError());
  SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
  if (!texture2)
      printf("Error creating texture from surface: %s\n", SDL_GetError());


  // Set destination rectangle for the text
  SDL_Rect dest1 = {475, 350-20, 550, 90};
  SDL_Rect dest2 = {475, 550-20, 550, 90};


  // Render the text
  SDL_RenderCopy(renderer, texture1, NULL, &dest1);
  SDL_RenderCopy(renderer, texture2, NULL, &dest2);

  SDL_DestroyTexture(texture1);
  SDL_DestroyTexture(texture2);

  // Clean up
  TTF_CloseFont(font);
  TTF_Quit();
}



void display_choose_difficulty(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0x31, 0x2E, 0x2B, 0xFF);
  SDL_Rect tfpW = {450, 100, 600, 850};
  SDL_RenderFillRect(renderer, &tfpW);

  SDL_Surface* cross_surface = IMG_Load("pieces/cross.png");
    if (cross_surface == NULL)
        printf("Error loading image: %s\n", SDL_GetError());
  SDL_Texture* cross_texture = SDL_CreateTextureFromSurface(renderer, cross_surface);
  SDL_Rect dst25 = { 1050, 20, 100, 100 };
  SDL_RenderCopy(renderer, cross_texture, NULL, &dst25);
  SDL_DestroyTexture(cross_texture);

  SDL_SetRenderDrawColor(renderer, 0x80, 0xa4, 0x64, 0xFF);
  SDL_Rect tfp1 = {500, 750, 500, 160};
  SDL_RenderFillRect(renderer, &tfp1);
  SDL_Rect tfp2 = {500, 550, 500, 160};
  SDL_RenderFillRect(renderer, &tfp2);
  SDL_Rect tfp3 = {500, 350, 500, 160};
  SDL_RenderFillRect(renderer, &tfp3);


  // Initialize TTF library
  if (TTF_Init() == -1)
      printf("Error initializing TTF: %s\n", TTF_GetError());

  // Load font
  TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 10);
  if (!font)
      printf("Error loading font: %s\n", TTF_GetError());

  // Render text to surface
  char text1[] = "Choose IA Difficulty";
  char text2[] = "        Easy        ";
  char text3[] = "       Medium       ";
  char text4[] = "        Hard        ";
  
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
  SDL_Surface *surface4 = TTF_RenderText_Solid(font, text4, color);
  if (!surface4)
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
  SDL_Texture *texture4 = SDL_CreateTextureFromSurface(renderer, surface4);
  if (!texture4)
      printf("Error creating texture from surface: %s\n", SDL_GetError());

  // Set destination rectangle for the text
  SDL_Rect dest1 = {475, 200-20, 550, 90};
  SDL_Rect dest2 = {475, 400-20, 550, 90};
  SDL_Rect dest3 = {475, 600-20, 550, 90};
  SDL_Rect dest4 = {475, 800-20, 550, 90};

  // Render the text
  SDL_RenderCopy(renderer, texture1, NULL, &dest1);
  SDL_RenderCopy(renderer, texture2, NULL, &dest2);
  SDL_RenderCopy(renderer, texture3, NULL, &dest3);
  SDL_RenderCopy(renderer, texture4, NULL, &dest4);

  SDL_FreeSurface(surface1);
  SDL_FreeSurface(surface2);
  SDL_FreeSurface(surface3);
  SDL_FreeSurface(surface4);

  SDL_DestroyTexture(texture1);
  SDL_DestroyTexture(texture2);
  SDL_DestroyTexture(texture3);
  SDL_DestroyTexture(texture4);

  // Clean up
  TTF_CloseFont(font);
  TTF_Quit();
}


void display_menu(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0x27, 0x24, 0x22, 0xFF);
  SDL_Rect dst = {0, 0, 1500, 980};
  SDL_RenderFillRect(renderer, &dst);

  SDL_Surface* logo_surface = IMG_Load("pieces/parametre.png");
  if (logo_surface == NULL)
      printf("Error loading image: %s\n", SDL_GetError());
  SDL_Texture* piece_texture = SDL_CreateTextureFromSurface(renderer, logo_surface);
  SDL_Rect dst25 = { 1430, 20, 50, 50 };
  SDL_RenderCopy(renderer, piece_texture, NULL, &dst25);
  SDL_DestroyTexture(piece_texture);
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

void draw_board(int theme, SDL_Renderer* renderer, struct Piece board[8][8], SDL_Surface* white_pion_surface,SDL_Surface* white_cavalier_surface,SDL_Surface* white_fou_surface,SDL_Surface* white_rook_surface,SDL_Surface* white_king_surface,SDL_Surface* white_queen_surface,SDL_Surface* black_pion_surface,SDL_Surface* black_fou_surface, SDL_Surface* black_cavalier_surface,SDL_Surface* black_rook_surface,SDL_Surface* black_king_surface, SDL_Surface* black_queen_surface){
  for (int x = 0; x < BOARD_SIZE; x++)
    for (int y = 0; y < BOARD_SIZE; y++){
      if(theme == 0)
        if ((x + y) % 2 == 0)
          SDL_SetRenderDrawColor(renderer, 0xEE, 0xEE, 0xD2, 0xFF);
        else
          SDL_SetRenderDrawColor(renderer, 0x76, 0x96, 0x56, 0xFF);
      else
        if ((x + y) % 2 == 0)
          SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xFF);
        else
          SDL_SetRenderDrawColor(renderer, 0x4b, 0x73, 0x99, 0x00);
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


void draw_board_fourth(SDL_Renderer* renderer){
  for (int x = 0; x < BOARD_SIZE; x++)
    for (int y = 0; y < BOARD_SIZE; y++){
      if ((x + y) % 2 == 0)
        SDL_SetRenderDrawColor(renderer, 0xEE, 0xEE, 0xD2, 0xFF);
      else
        SDL_SetRenderDrawColor(renderer, 0x76, 0x96, 0x56, 0xFF);
      display_ttf(renderer, x, y);
      SDL_Rect rect = { y * TILE_SIZE, x * TILE_SIZE, TILE_SIZE, TILE_SIZE };
      SDL_RenderFillRect(renderer, &rect);
    }
}


void piece_fourth(SDL_Renderer* renderer, struct Piece board[8][8], SDL_Surface* white_pion_surface,SDL_Surface* white_cavalier_surface,SDL_Surface* white_fou_surface,SDL_Surface* white_rook_surface,SDL_Surface* white_king_surface,SDL_Surface* white_queen_surface,SDL_Surface* black_pion_surface,SDL_Surface* black_fou_surface, SDL_Surface* black_cavalier_surface,SDL_Surface* black_rook_surface,SDL_Surface* black_king_surface, SDL_Surface* black_queen_surface){
  
  int y = 8;
  display_piece(renderer, black_pion_surface, y, 1);
  display_piece(renderer, black_cavalier_surface, y, 2);
  display_piece(renderer, black_fou_surface, y, 3);
  display_piece(renderer, black_rook_surface, y, 4);
  display_piece(renderer, black_queen_surface, y, 5);
  display_piece(renderer, black_king_surface, y, 6);
  y = 9;
  display_piece(renderer, white_pion_surface, y, 1);
  display_piece(renderer, white_cavalier_surface, y, 2);
  display_piece(renderer, white_fou_surface, y, 3);
  display_piece(renderer, white_rook_surface, y, 4);
  display_piece(renderer, white_queen_surface, y, 5);
  display_piece(renderer, white_king_surface, y, 6);
}


void play_but(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0x80, 0xa4, 0x64, 0xFF);
  SDL_Rect tfp1 = {1100, 890, 300, 70};
  SDL_RenderFillRect(renderer, &tfp1);

    // Initialize TTF library
  if (TTF_Init() == -1)
      printf("Error initializing TTF: %s\n", TTF_GetError());

  // Load font
  TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 10);
  if (!font)
      printf("Error loading font: %s\n", TTF_GetError());

  // Render text to surface
  char text0[] = "     Load     ";

  SDL_Color color;
  color = (SDL_Color){238, 238, 210};

  SDL_Surface *surface0 = TTF_RenderText_Solid(font, text0, color);
  if (!surface0)
      printf("Error rendering text: %s\n", TTF_GetError());

  // Convert surface to texture
  SDL_Texture *texture0 = SDL_CreateTextureFromSurface(renderer, surface0);
  if (!texture0)
      printf("Error creating texture from surface: %s\n", SDL_GetError());


  // Set destination rectangle for the text
  SDL_Rect dest0 = {1100, 900, 300, 50};

  // Render the text
  SDL_RenderCopy(renderer, texture0, NULL, &dest0);

  SDL_FreeSurface(surface0);

  SDL_DestroyTexture(texture0);

  // Clean up
  TTF_CloseFont(font);
  TTF_Quit();
}



void display_score(SDL_Renderer* renderer, int score){
  SDL_SetRenderDrawColor(renderer, 0x27, 0x24, 0x22, 0xFF);
  SDL_Rect tfp1 = {1020, 820, 30 ,20};
  SDL_Rect tfp2 = {1020, 130, 30 ,20};
  SDL_RenderFillRect(renderer, &tfp1);
  SDL_RenderFillRect(renderer, &tfp2);

  // Initialize TTF library
  if (TTF_Init() == -1)
      printf("Error initializing TTF: %s\n", TTF_GetError());


  // Load font
  TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 20);
  if (!font)
      printf("Error loading font: %s\n", TTF_GetError());

  // Render text to surface
  char text[10];

  SDL_Color color;
  color = (SDL_Color){238, 238, 210};
  sprintf(text, "+%d", abs(score));

  SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
  if (!surface)
      printf("Error rendering text: %s\n", TTF_GetError());

  // Convert surface to texture
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (!texture)
      printf("Error creating texture from surface: %s\n", SDL_GetError());

  // Set destination rectangle for the text
  SDL_Rect dest;
  if(score >= 0)
  {
    dest.x = 1020;
    dest.y = 820;
  }
  else
  {
    dest.x = 1020;
    dest.y = 130;
  }
  dest.w = 30;
  dest.h = 20;
  // Render the text
  SDL_RenderCopy(renderer, texture, NULL, &dest);

  // Clean up
  TTF_CloseFont(font);
  TTF_Quit();
}
void display_theme(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0x31, 0x2E, 0x2B, 0xFF);
  SDL_Rect tfpW = {450, 250, 600, 600};
  SDL_RenderFillRect(renderer, &tfpW);

  SDL_SetRenderDrawColor(renderer, 0x80, 0xa4, 0x64, 0xFF);
  SDL_Rect tfp1 = {500, 500, 500, 160};
  SDL_RenderFillRect(renderer, &tfp1);
  SDL_Rect tfp2 = {500, 700, 240, 100};
  SDL_RenderFillRect(renderer, &tfp2);
  SDL_SetRenderDrawColor(renderer, 0x4b, 0x73, 0x99, 0x00);
  SDL_Rect tfp3 = {760, 700, 240, 100};
  SDL_RenderFillRect(renderer, &tfp3);

  // Initialize TTF library
  if (TTF_Init() == -1)
      printf("Error initializing TTF: %s\n", TTF_GetError());

  // Load font
  TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 10);
  if (!font)
      printf("Error loading font: %s\n", TTF_GetError());

  // Render text to surface
  char text1[] = "    Choose Theme    ";
  char text2[] = "        Back        ";
  
  SDL_Color color;
  color = (SDL_Color){238, 238, 210};

  SDL_Surface *surface1 = TTF_RenderText_Solid(font, text1, color);
  if (!surface1)
      printf("Error rendering text: %s\n", TTF_GetError());
  SDL_Surface *surface2 = TTF_RenderText_Solid(font, text2, color);
  if (!surface2)
      printf("Error rendering text: %s\n", TTF_GetError());


  // Convert surface to texture
  SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
  if (!texture1)
      printf("Error creating texture from surface: %s\n", SDL_GetError());
  SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
  if (!texture2)
      printf("Error creating texture from surface: %s\n", SDL_GetError());


  // Set destination rectangle for the text
  SDL_Rect dest1 = {475, 350-20, 550, 90};
  SDL_Rect dest2 = {475, 550-20, 550, 90};


  // Render the text
  SDL_RenderCopy(renderer, texture1, NULL, &dest1);
  SDL_RenderCopy(renderer, texture2, NULL, &dest2);

  SDL_DestroyTexture(texture1);
  SDL_DestroyTexture(texture2);

  // Clean up
  TTF_CloseFont(font);
  TTF_Quit();
}