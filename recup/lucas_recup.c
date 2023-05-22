#include <stdio.h>
#include <math.h>
#include "src/gui.c"
#include "src/print_board.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LINE_LENGTH 1024
#define MAX_MOVES_PER_LINE 256
#define MAX_MOVES_HISTORY 50


#define couleur(param) printf("\033[%sm", param)


void afficheDeplacements(struct Deplacement* deplacements, int nbDeplacements) {
    for (int i = 0; i < nbDeplacements; i++)
        printf("Deplacement %d: %c%d -> %c%d\n", i+1, 'a' + deplacements[i].yDepart, 8 - deplacements[i].xDepart, 'a' + deplacements[i].yArrivee, 8 - deplacements[i].xArrivee);
}
















int RoiEnEchec_player(int xRoi,int yRoi, int couleur,struct Piece board[8][8],int xRoiEnnemie, int yRoiEnnemie)
{
 int j;
 int i;
    if (couleur == BLANC)
    {
        
        i = xRoi-1;
        j = yRoi-1;
        if (i >= 0 && j >= 0 && board[i][j].type == PION && board[i][j].couleur != couleur)
        {
            //printf("test1\n");
            return 1;
        }
        i = xRoi-1;
        j = yRoi+1;
        if (i >= 0 && j < 8 && board[i][j].type == PION && board[i][j].couleur != couleur)
        {
            //printf("test2\n");
            return 1;
        } 
    }
    else
    {
        i = xRoi+1;
        j = yRoi-1;
        if (i < 8 && j >= 0 && board[i][j].type == PION && board[i][j].couleur != couleur)
        {
            //printf("test3\n");
            return 1;
        }
        i = xRoi+1;
        j = yRoi+1;
        if (i < 8 && j < 8 && board[i][j].type == PION && board[i][j].couleur != couleur)
        {
            //printf("test4\n");
            return 1;
        }
    }



if (xRoi - 2 >= 0) {
        if (yRoi - 1 >= 0) {
            if (board[xRoi - 2][yRoi - 1].type == CAVALIER && board[xRoi - 2][yRoi - 1].couleur != couleur ) {
                //printf("test5\n");
            return 1;
            
            }
        }
        if (yRoi + 1 < 8) {
            if (board[xRoi - 2][yRoi + 1].type == CAVALIER && board[xRoi - 2][yRoi + 1].couleur != couleur) {
                //printf("test6\n");
            return 1;
            
            
            }
        }
    }

    
    if (xRoi + 2 < 8) {
        if (yRoi - 1 >= 0) {
            if (board[xRoi + 2][yRoi - 1].type == CAVALIER && board[xRoi + 2][yRoi - 1].couleur != couleur) {
                //printf("test7\n");
            return 1;
            }
        }
        if (yRoi + 1 < 8) {
            if (board[xRoi + 2][yRoi + 1].type == CAVALIER && board[xRoi + 2][yRoi + 1].couleur != couleur) {
                //printf("test8\n");
            return 1;
            }
        }
    }
    if (yRoi - 2 >= 0) {
        if (xRoi - 1 >= 0) {
            if (board[xRoi - 1][yRoi - 2].type == CAVALIER && board[xRoi - 1][yRoi - 2].couleur != couleur) {
                //printf("test9\n");
            return 1;
            }
        }
        if (xRoi + 1 < 8) {
            if (board[xRoi + 1][yRoi - 2].type == CAVALIER && board[xRoi + 1][yRoi - 2].couleur != couleur) {
                //printf("test10\n");
            return 1;
            }
        }
    }
    if (yRoi + 2 < 8) {
        if (xRoi - 1 >= 0) {
            if (board[xRoi - 1][yRoi + 2].type == CAVALIER && board[xRoi - 1][yRoi + 2].couleur != couleur) {
                //printf("test11\n");
            return 1;
            }
        }
        if (xRoi + 1 < 8) {
            if (board[xRoi + 1][yRoi + 2].type == CAVALIER && board[xRoi + 1][yRoi + 2].couleur != couleur) {
                //printf("test12\n");
            return 1;
        }
        }
    }






    //printf("test\n");
    i = xRoi+1;
    j = yRoi+1;




    while(i < 8 && j < 8 && (board[i][j].type == PAS_DE_PIECE || (board[i][j].type == ROI && board[i][j].couleur == couleur)))
    {
        i++;
        j++;
    }
    if (i < 8 && j < 8 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur != couleur )
    {
        //printf("test13\n");
        return 1;
    }


    i = xRoi-1;
    j = yRoi-1;
    while(i >= 0 && j >= 0 && (board[i][j].type == PAS_DE_PIECE  || (board[i][j].type == ROI && board[i][j].couleur == couleur)))
    {
        i--;
        j--;
    }
    if (i >= 0 && j >= 0 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur != couleur)
    {
        //printf("test14\n");
        return 1;
    }


    i = xRoi-1;
    j = yRoi+1;
    while(i >= 0 && j < 8 && (board[i][j].type == PAS_DE_PIECE || (board[i][j].type == ROI && board[i][j].couleur == couleur)))
    {
        i--;
        j++;
    }
    if (i >= 0 && j < 8 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur != couleur)
    {
        //printf("test15\n");
        return 1;
    }


    i = xRoi+1;
    j = yRoi-1;
    while(i < 8 && j >= 0 && (board[i][j].type == PAS_DE_PIECE || (board[i][j].type == ROI && board[i][j].couleur == couleur)))
    {
        i++;
        j--;
    }
    if (i < 8 && j >= 0 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur != couleur)
    {
        //printf("test16\n");
        return 1;
    }


    i = xRoi+1;
    j = yRoi;
    while(i < 8 && (board[i][j].type == PAS_DE_PIECE  || (board[i][j].type == ROI && board[i][j].couleur == couleur)))
    {
        i++;
    }
    if (i < 8 && (board[i][j].type == DAME || board[i][j].type == TOUR) && board[i][j].couleur != couleur)
    {
        //printf("test17\n");
        return 1;
    }


    i = xRoi-1;
    j = yRoi;
    while(i >= 0 && (board[i][j].type == PAS_DE_PIECE  || (board[i][j].type == ROI && board[i][j].couleur == couleur)))
    {
        i--;
    }
    if (i >= 0 && (board[i][j].type == DAME || board[i][j].type == TOUR) && board[i][j].couleur != couleur)
    {
        //printf("test18\n");
        return 1;
    }


    i = xRoi;
    j = yRoi+1;
    while(j < 8 && (board[i][j].type == PAS_DE_PIECE || (board[i][j].type == ROI && board[i][j].couleur == couleur)))
    {
        j++;
    }
    if (j < 8 && (board[i][j].type == DAME || board[i][j].type == TOUR) && board[i][j].couleur != couleur)
    {
        //printf("test19\n");
        return 1;
    }


    i = xRoi;
    j = yRoi-1;
    while(j >= 0 && (board[i][j].type == PAS_DE_PIECE || (board[i][j].type == ROI && board[i][j].couleur == couleur)))
    {
        j--;
    }


    if (j >= 0 && (board[i][j].type == DAME || board[i][j].type == TOUR) && board[i][j].couleur != couleur)
    {
        //printf("test20\n");
        return 1;
    }



    if (xRoi ==  xRoiEnnemie || xRoi ==  xRoiEnnemie-1  || xRoi ==  xRoiEnnemie+1 )
    {
        if (yRoi ==  yRoiEnnemie || yRoi ==  yRoiEnnemie-1  || yRoi ==  yRoiEnnemie+1 )
        {
            return 1;
        }
    }
    

    /*
    if (case_existe(xRoi+1,yRoi+1) && board[xRoi+1][yRoi+1].type == ROI &&  board[xRoi+1][yRoi+1].couleur != couleur)
    {
        printf("test21\n");
        return 1;
    }
    if (board[xRoi][yRoi+1].type == ROI &&  board[xRoi][yRoi+1].couleur != couleur)
    {
        printf("test22\n");
        return 1;
    }
    if (board[xRoi-1][yRoi+1].type == ROI &&  board[xRoi-1][yRoi+1].couleur != couleur)
    {
        printf("test23\n");
        return 1;
    }
    if (board[xRoi+1][yRoi].type == ROI &&  board[xRoi+1][yRoi].couleur != couleur)
    {
        printf("test24\n");
        return 1;
    }
    if (board[xRoi-1][yRoi].type == ROI &&  board[xRoi-1][yRoi].couleur != couleur)
    {
        printf("test25\n");
        return 1;
    }
    if (board[xRoi+1][yRoi-1].type == ROI &&  board[xRoi+1][yRoi-1].couleur != couleur)
    {
        printf("test26\n");
        return 1;
    }
    if (board[xRoi][yRoi-1].type == ROI &&  board[xRoi][yRoi-1].couleur != couleur)
    {
        printf("test27\n");
        return 1;
    }
    if (board[xRoi-1][yRoi-1].type == ROI &&  board[xRoi-1][yRoi-1].couleur != couleur)
    {
        printf("test28\n");
        return 1;
    }
    */
    return 0;
}


// return -1 quand pas d'échec, return -2 quand 2 ou plus d'échec, sinon un nombre représentant la position de la pièce qui menace, la dixaine pour x, et l'uniter pour y
int RoiEnEchec_bot(int xRoi,int yRoi,struct Piece board[8][8])
{
    int cpt = 0;
    int i;
    int j;
    int posX, posY;

    if (board[xRoi][yRoi].couleur == BLANC)
    {
        i = xRoi-1;
        j = yRoi-1;
        if (i >= 0 && j >= 0 && board[i][j].type == PION && board[i][j].couleur != board[xRoi][yRoi].couleur)
        {
            cpt++;
            posX = i;
            posY = j;
        }
        i = xRoi-1;
        j = yRoi+1;
        if (i >= 0 && j < 8 && board[i][j].type == PION && board[i][j].couleur != board[xRoi][yRoi].couleur)
        {
            cpt ++;
            if (cpt == 2)
                return -2;
            posX = i;
            posY = j;
        } 
    }
    else
    {
        i = xRoi+1;
        j = yRoi-1;
        if (i < 8 && j >= 0 && board[i][j].type == PION && board[i][j].couleur != board[xRoi][yRoi].couleur)
        {
            cpt++;
            posX = i;
            posY = j;
        }
        i = xRoi+1;
        j = yRoi+1;
        if (i < 8 && j < 8 && board[i][j].type == PION && board[i][j].couleur != board[xRoi][yRoi].couleur)
        {
            cpt ++;
            if (cpt == 2)
                return -2;
            posX = i;
            posY = j;
        }
    }

// verification cavalier

if (xRoi - 2 >= 0) {
        if (yRoi - 1 >= 0) {
            if (board[xRoi - 2][yRoi - 1].type == CAVALIER && board[xRoi - 2][yRoi - 1].couleur != board[xRoi][yRoi].couleur ) {

            cpt ++;
            if (cpt == 2)
                return -2;
            posX = xRoi -2;
            posY = yRoi - 1;

            }
        }
        if (yRoi + 1 < 8) {
            if (board[xRoi - 2][yRoi + 1].type == CAVALIER && board[xRoi - 2][yRoi + 1].couleur != board[xRoi][yRoi].couleur) {
            cpt ++;
            if (cpt == 2)
                return -2;
            posX = xRoi -2;
            posY = yRoi + 1;

            }
        }

    }
    if (xRoi + 2 < 8) {
        if (yRoi - 1 >= 0) {
            if (board[xRoi + 2][yRoi - 1].type == CAVALIER && board[xRoi + 2][yRoi - 1].couleur != board[xRoi][yRoi].couleur) {
            cpt ++;
            if (cpt == 2)
                return -2;
            posX = xRoi +2;
            posY = yRoi - 1;
            }
        }
        if (yRoi + 1 < 8) {
            if (board[xRoi + 2][yRoi + 1].type == CAVALIER && board[xRoi + 2][yRoi + 1].couleur != board[xRoi][yRoi].couleur) {
            cpt ++;
            if (cpt == 2)
                return -2;
            posX = xRoi +2;
            posY = yRoi + 1;
            }
        }
    }
    if (yRoi - 2 >= 0) {
        if (xRoi - 1 >= 0) {
            if (board[xRoi - 1][yRoi - 2].type == CAVALIER && board[xRoi - 1][yRoi - 2].couleur != board[xRoi][yRoi].couleur) {
            cpt ++;
            if (cpt == 2)
                return -2;
            posX = xRoi -1;
            posY = yRoi - 2;
            }
        }
        if (xRoi + 1 < 8) {
            if (board[xRoi + 1][yRoi - 2].type == CAVALIER && board[xRoi + 1][yRoi - 2].couleur != board[xRoi][yRoi].couleur) {
            cpt ++;
            if (cpt == 2)
                return -2;
            posX = xRoi +1;
            posY = yRoi - 2;
            }
        }
    }
    if (yRoi + 2 < 8) {
        if (xRoi - 1 >= 0) {
            if (board[xRoi - 1][yRoi + 2].type == CAVALIER && board[xRoi - 1][yRoi + 2].couleur != board[xRoi][yRoi].couleur) {
            cpt ++;
            if (cpt == 2)
                return -2;
            posX = xRoi -1;
            posY = yRoi + 2;
            }
        }
        if (xRoi + 1 < 8) {
            if (board[xRoi + 1][yRoi + 2].type == CAVALIER && board[xRoi + 1][yRoi + 2].couleur != board[xRoi][yRoi].couleur) {
            cpt ++;
            if (cpt == 2)
                return -2;
            posX = xRoi + 1;
            posY = yRoi + 2;
            }
        }
    }





    i = xRoi+1;
    j = yRoi+1;
    while(i < 8 && j < 8 && board[i][j].type == PAS_DE_PIECE)
    {
        i++;
        j++;
    }
    if (i < 8 && j < 8 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur != board[xRoi][yRoi].couleur)
    {
        cpt ++;
        if (cpt == 2)
            return -2;
        posX = i;
        posY = j;
    }


    i = xRoi-1;
    j = yRoi-1;
    while(i >= 0 && j >= 0 && board[i][j].type == PAS_DE_PIECE)
    {
        i--;
        j--;
    }
    if (i >= 0 && j >= 0 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur != board[xRoi][yRoi].couleur)
    {
        cpt ++;
        if (cpt == 2)
            return -2;
        posX = i;
        posY = j;
    }


    i = xRoi-1;
    j = yRoi+1;
    while(i >= 0 && j < 8 && board[i][j].type == PAS_DE_PIECE)
    {
        i--;
        j++;
    }
    if (i >= 0 && j < 8 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur != board[xRoi][yRoi].couleur)
    {
        cpt ++;
        if (cpt == 2)
            return -2;
        posX = i;
        posY = j;
    }


    i = xRoi+1;
    j = yRoi-1;
    while(i < 8 && j >= 0 && board[i][j].type == PAS_DE_PIECE)
    {
        i++;
        j--;
    }
    if (i < 8 && j >= 0 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur != board[xRoi][yRoi].couleur)
    {
        cpt ++;
        if (cpt == 2)
            return -2;
        posX = i;
        posY = j;
    }


    i = xRoi+1;
    j = yRoi;
    while(i < 8 && board[i][j].type == PAS_DE_PIECE)
    {
        i++;
    }
    if (i < 8 && (board[i][j].type == DAME || board[i][j].type == TOUR) && board[i][j].couleur != board[xRoi][yRoi].couleur)
    {
        cpt ++;
        if (cpt == 2)
            return -2;
        posX = i;
        posY = j;
    }


    i = xRoi-1;
    j = yRoi;
    while(i >= 0 && board[i][j].type == PAS_DE_PIECE)
    {
        i--;
    }
    if (i >= 0 && (board[i][j].type == DAME || board[i][j].type == TOUR) && board[i][j].couleur != board[xRoi][yRoi].couleur)
    {
        cpt ++;
        if (cpt == 2)
            return -2;
        posX = i;
        posY = j;
    }


    i = xRoi;
    j = yRoi+1;
    while(j < 8 && board[i][j].type == PAS_DE_PIECE)
    {
        j++;
    }
    if (j < 8 && (board[i][j].type == DAME || board[i][j].type == TOUR) && board[i][j].couleur != board[xRoi][yRoi].couleur)
    {
        cpt ++;
        if (cpt == 2)
            return -2;
        posX = i;
        posY = j;
    }


    i = xRoi;
    j = yRoi-1;
    while(j >= 0 && board[i][j].type == PAS_DE_PIECE)
    {
        j--;
    }
    if (j >= 0 && (board[i][j].type == DAME || board[i][j].type == TOUR) && board[i][j].couleur != board[xRoi][yRoi].couleur)
    {
        cpt ++;
        if (cpt == 2)
            return -2;
        posX = i;
        posY = j;
    }
    if (cpt == 1)
        return posX*10+posY;
    return -1;
}



void ajout_deplacement(int x, int y ,int xArriver, int yArriver,struct Deplacement deplacements[], int* nombreDeplacements ){
            //printf("test13 %d\n",*nombreDeplacements);
            deplacements[*nombreDeplacements].xDepart = x;
            deplacements[*nombreDeplacements].yDepart = y;
            deplacements[*nombreDeplacements].xArrivee = xArriver;
            deplacements[*nombreDeplacements].yArrivee = yArriver;
            //printf("test14\n");
            (*nombreDeplacements)++;

}


int case_existe(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// 0 quand pas de clouage ; 1 quand clouage verticale ; 2 horizontale ; 3 diagonale croissante ; 4 diagonale décroissante
int piece_cloue(int x, int y, int xRoi, int yRoi, struct Piece board[8][8]){
    int i;
    int j;
    if (y == yRoi){
        if(x < xRoi){
            i = x+1;
            while(i != xRoi)
            {
                
                if (board[i][y].type != PAS_DE_PIECE)
                {
                    //printf("piece_cloue test 1 %i \n", 0);
                    return 0;
                }
                i++;
            }
            i = x-1;
            while( i >=0 && board[i][y].type == PAS_DE_PIECE)
            {
                i--;
            }
            if ( i>=0 && (board[i][y].type == DAME || board[i][y].type == TOUR ) && board[i][y].couleur != board[x][y].couleur )
            {
                //printf("piece_cloue test 2 %i \n", 1);
                return 1;
            }
            
        }
        else
        {
            i = x-1;
            while(i != xRoi)
            {
                
                if (board[i][x].type != PAS_DE_PIECE)
                {
                    //printf("piece_cloue test 3 %i \n", 0);
                    return 0;
                }
                i--;
            }
            i = x+1;
            while( i<8 && board[i][y].type == PAS_DE_PIECE)
            {
                i++;
            }
            if ( i<8 && (board[i][y].type == DAME || board[i][y].type == TOUR ) && board[i][y].couleur != board[x][y].couleur )
            {
                //printf("piece_cloue test 4 %i \n", 1);
                return 1;
            }
        }
        //printf("piece_cloue test 5 %i \n", 0);
        return 0;

    }
    // beug régler   if (x == yRoi)
    if (x == xRoi)
    {
       if(y < yRoi){
            i = y+1;
            while(i != yRoi)
            {
                if (board[x][i].type != PAS_DE_PIECE)
                {
                    return 0;
                }
                i++;
            }
            i = y-1;
            while( i>=0 && board[x][i].type == PAS_DE_PIECE)
            {
                i--;
            }
            if ( i>=0 && (board[x][i].type == DAME || board[x][i].type == TOUR ) && board[x][i].couleur != board[x][y].couleur )
            {
                return 2;
            }

        }
        else
        {
            i = y-1;
            while(i != yRoi)
            {
                if (board[x][i].type != PAS_DE_PIECE)
                {
                    return 0;
                }
                i--;
            }
            i = y+1;
            while( i<8 && board[x][i].type == PAS_DE_PIECE)
            {
                i++;
            }
            if ( i<8 && (board[x][i].type == DAME || board[x][i].type == TOUR) && board[x][y].couleur != board[x][i].couleur )
            {
                return 2;
            }
        }
        return 0;
    }
    if (x-xRoi == y-yRoi)

    {
        if (x < xRoi)
        {
            i = x+1;
            j = y+1;
            while(i != xRoi)
            {
                if (board[i][j].type != PAS_DE_PIECE)
                {
                    //printf("piece_cloue test 6 %i \n", 0);
                    return 0;
                }
                i++;
                j++;
            }
            i = x-1;
            j = y-1;
            while( (i >=0 && j >=0) && board[i][j].type == PAS_DE_PIECE)
            {
                i--;
                j--;
            }
            //printf("piece_cloue test 15 %i  %i\n", i,j);
            //printf("piece_cloue test 15 %i  \n", (board[i][j].type == DAME || board[i][j].type == FOU ) );
            //printf("piece_cloue test 15 %i  \n", board[i][j].couleur != board[x][y].couleur);

            if ( (i >=0 && j >=0) && (board[i][j].type == DAME || board[i][j].type == FOU ) && board[i][j].couleur != board[x][y].couleur )
            {
                return 4;
            }
        }
        else
        {
            i = x-1;
            j = y-1;
            while(i != xRoi)
            {
                if (board[i][j].type != PAS_DE_PIECE)
                {
                    //printf("piece_cloue test 7 %i \n", 0);
                    return 0;
                }
                i--;
                j--;
            }
            i = x+1;
            j = y+1;
            while( ( i<8 && j<8 ) && board[i][j].type == PAS_DE_PIECE)
            {
                i++;
                j++;
            }
            if ( ( i<8 && j<8 ) && (board[i][j].type == DAME || board[i][j].type == FOU ) && board[i][j].couleur != board[x][y].couleur )
            {
                return 4;
            }
        }
        //printf("piece_cloue test 8 %i \n", 0);
        return 0;
    }
    if (x-xRoi == -(y-yRoi))
    {
        if (x < xRoi)
        {
            i = x+1;
            j = y-1;
            while(i != xRoi)
            {
                if (board[i][j].type != PAS_DE_PIECE)
                {
                    //printf("piece_cloue test 9 %i %i \n", i,j);
                    //printf("piece_cloue test 9 %i \n", 0);
                    return 0;
                }
                i++;
                j--;
            }
            i = x-1;
            j = y+1;
            while( case_existe(i,j) && board[i][j].type == PAS_DE_PIECE)
            {
                i--;
                j++;
            }
            if ( case_existe(i,j) && (board[i][j].type == DAME || board[i][j].type == FOU ) && board[i][j].couleur != board[x][y].couleur )
            {
                return 3;
            }
        }
        else
        {
            i = x-1;
            j = y+1;
            while(i != xRoi)
            {
                if (board[i][j].type != PAS_DE_PIECE)
                {
                    //printf("piece_cloue test 10 %i \n", 0);
                    return 0;
                }
                i--;
                j++;
            }
            i = x+1;
            j = y-1;
            while( case_existe(i,j) && board[i][j].type == PAS_DE_PIECE)
            {
                i++;
                j--;
            }
            if ( case_existe(i,j) && (board[i][j].type == DAME || board[i][j].type == FOU ) && board[i][j].couleur != board[x][y].couleur )
            {
                return 3;
            }
        }
    }
    //printf("piece_cloue test 11 %i \n", 0);
    return 0;
}



void ajouterDeplacementPion(int x, int y, int xRoi, int yRoi, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]) {
    //printf("test_pion 1 : %i  %i \n", xRoi, yRoi);
    int cloue = piece_cloue(x,y,xRoi,yRoi,board);

    //printf("test_pion 2 : %i \n", cloue);
    if (board[x][y].couleur == 1 ) {

        if( (cloue == 0 || cloue == 1) && board[x-1][y].type == PAS_DE_PIECE) {
            if (x > 0) {
                //printf("test 11 : %d \n",board[x-1][y].type );
                ajout_deplacement(x, y ,x-1 , y,deplacements,nombreDeplacements ); 
            }
            if (x == 6 && board[x-2][y].type == PAS_DE_PIECE) {
                //printf("test 12 : %d \n",board[x-2][y].type );
                ajout_deplacement(x, y ,x-2 , y,deplacements,nombreDeplacements ); 
            }
        }
        if ( (cloue == 0 || cloue == 3) && case_existe(x-1,y+1) && board[x-1][y+1].couleur == 0 ) {
            //printf("test 5 : %d \n",board[x-1][y+1].type );
            ajout_deplacement(x, y ,x-1 , y+1,deplacements,nombreDeplacements );    
        }
        if ( (cloue == 0 || cloue == 4 )&&  case_existe(x-1,y-1) && board[x-1][y-1].couleur == 0 ) {
            //printf("test 6 : %d \n",board[x-1][y-1].type );
            ajout_deplacement(x, y ,x-1 , y-1,deplacements,nombreDeplacements );    
        }
        // prise en passant

    }
    else {

        if( (cloue == 0 || cloue == 1) && board[x+1][y].type == PAS_DE_PIECE) {
            if (x < 7) {
                //printf("test 9 : %d \n",board[x+1][y].type );
                ajout_deplacement(x, y ,x+1 , y,deplacements,nombreDeplacements ); 
            }
            if (x == 1 && board[x+2][y].type == PAS_DE_PIECE) {
                //printf("test 10 : %d \n",board[x+2][y].type );
                ajout_deplacement(x, y ,x+2 , y,deplacements,nombreDeplacements ); 
            }
        }
        if ( (cloue == 0 || cloue == 4) && case_existe(x+1,y+1) && board[x+1][y+1].couleur == 1 ) {
            //printf("test 7 : %d \n",board[x+1][y+1].type );
            ajout_deplacement(x, y ,x+1 , y+1,deplacements,nombreDeplacements );    
        }
        if ( (cloue == 0 || cloue == 3) && case_existe(x+1,y-1) && board[x+1][y-1].couleur == 1 ) {
            //printf("test 8 : %d \n",board[x+1][y-1].type );
            ajout_deplacement(x, y ,x+1 , y-1,deplacements,nombreDeplacements );    
        }
        // prise en passant
	}
}

// void ajouterDeplacement(int x, int y, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]) 



void ajouterDeplacementCavalier(int x, int y, int xRoi, int yRoi, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]) {

    if (piece_cloue(x,y,xRoi,yRoi,board) != 0){
        return;
    }
    if (x - 2 >= 0) {
        if (y - 1 >= 0) {
            if (board[x - 2][y - 1].couleur != board[x][y].couleur) {
                ajout_deplacement(x, y ,x-2 , y-1,deplacements,nombreDeplacements );
            }
        }
        if (y + 1 < 8) {
            if (board[x - 2][y + 1].couleur != board[x][y].couleur) {
                ajout_deplacement(x, y ,x-2 , y+1,deplacements,nombreDeplacements );
            }
        }
    }
    if (x + 2 < 8) {
        if (y - 1 >= 0) {
            if (board[x + 2][y - 1].couleur != board[x][y].couleur) {
                ajout_deplacement(x, y ,x+2 , y-1,deplacements,nombreDeplacements );
            }
        }
        if (y + 1 < 8) {
            if (board[x + 2][y + 1].couleur != board[x][y].couleur) {
                ajout_deplacement(x, y ,x+2 , y+1,deplacements,nombreDeplacements );
            }
        }
    }
    if (y - 2 >= 0) {
        if (x - 1 >= 0) {
            if (board[x - 1][y - 2].couleur != board[x][y].couleur) {
                ajout_deplacement(x, y ,x-1 , y-2,deplacements,nombreDeplacements );
            }
        }
        if (x + 1 < 8) {
            if (board[x + 1][y - 2].couleur != board[x][y].couleur) {
                ajout_deplacement(x, y ,x+1 , y-2,deplacements,nombreDeplacements );
            }
        }
    }
    if (y + 2 < 8) {
        if (x - 1 >= 0) {
            if (board[x - 1][y + 2].couleur != board[x][y].couleur) {
                ajout_deplacement(x, y ,x-1 , y+2,deplacements,nombreDeplacements );
            }
        }
        if (x + 1 < 8) {
            if (board[x + 1][y + 2].couleur != board[x][y].couleur) {
                ajout_deplacement(x, y ,x+1 , y+2,deplacements,nombreDeplacements );
            }
        }
    }
}


void ajouterDeplacementTour(int x, int y, int xRoi, int yRoi, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]) {

    int cloue = piece_cloue(x,y,xRoi,yRoi,board);

    ////printf("test 2 : %i  %i \n", x, y);

    ////printf("test 1 : %i \n", cloue);

    // boucle pour trouver les déplacements vers le haut
    if (cloue == 0 || cloue == 1)
    {
        for (int i = x - 1; i >= 0; i--) {
            if (board[i][y].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,i , y,deplacements,nombreDeplacements ); 
            } else {
                if (board[i][y].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,i , y,deplacements,nombreDeplacements ); 
                }
                break;
            }
        }
        // boucle pour trouver les déplacements vers le bas
        for (int i = x + 1; i < 8; i++) {
            if (board[i][y].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,i , y,deplacements,nombreDeplacements ); 
            } else {
                if (board[i][y].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,i , y,deplacements,nombreDeplacements ); 
                }
                break;
            }
        }
    }
    if (cloue == 0 || cloue == 2)
    {
        // boucle pour trouver les déplacements vers la gauche
        for (int j = y - 1; j >= 0; j--) {
            if (board[x][j].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,x , j,deplacements,nombreDeplacements ); 
            } else {
                if (board[x][j].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,x , j,deplacements,nombreDeplacements ); 
                }
                break;
            }
        }
        // boucle pour trouver les déplacements vers la droite
        for (int j = y + 1; j < 8; j++) {
            if (board[x][j].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,x , j,deplacements,nombreDeplacements ); 
            } else {
                if (board[x][j].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,x , j,deplacements,nombreDeplacements ); 
                }
                break;
            }
        }
    }
}


void ajouterDeplacementFou(int x, int y, int xRoi, int yRoi, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]) {
    int i, j;
    int cloue = piece_cloue(x,y,xRoi,yRoi,board);
    //printf("fou clouer %i\n", cloue);
    if (cloue == 0 || cloue == 4)
    {
        for (i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++) {
            if (board[i][j].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
            } else {
                if (board[i][j].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
                }
                break;
            }
        }
        for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
            } else {
                if (board[i][j].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
                }
                break;
            }
        }
    }
    if (cloue == 0 || cloue == 3)
    {
        for (i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--) {
            if (board[i][j].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
            } else {
                if (board[i][j].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
                }
                break;
            }
        }
        for (i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++) {
            if (board[i][j].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
            } else {
                if (board[i][j].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
                }
                break;
            }
        }
    }

}


void ajouterDeplacementRoi(int x, int y, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]) {
    // Vérification des 8 cases adjacentes au roi
    int positionEnnemie = trouverRoi(!board[x][y].couleur,board);
    int xRoiEnnemie = positionEnnemie/10;
    int yRoiEnnemie = positionEnnemie%10;
    int couleur = board[x][y].couleur;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (case_existe(x + i, y + j) && (i != 0 || j != 0)) {
                
                if (board[x + i][y + j].couleur != couleur &&  0 == RoiEnEchec_player(x+i,y+j,couleur,board,xRoiEnnemie,yRoiEnnemie)) {
                    ajout_deplacement(x, y ,x+i , y+j,deplacements,nombreDeplacements );
                }
            }
        }
    }


 
    //printf("tst damien %i %i %i %i\n",a.xArrivee,a.xDepart,a.yArrivee,a.yDepart);
    
    
    //printf("test30 %i \n",board[x][y].test_roquable==1 &&((board[x][y].couleur == BLANC && x == 7 && y == 5) ||(board[x][y].couleur == NOIR && x == 0 && y == 5)));
    //printf("test 25 %i \n", board[x][y+3].test_roquable==1 && board[x][y+1].type == PAS_DE_PIECE && board[x][y+2].type == PAS_DE_PIECE);
    // Vérification pour le roque
    //printf("test roquable %i\n",board[x][y].test_roquable);
    if (board[x][y].test_roquable==1 &&((board[x][y].couleur == BLANC && x == 7 && y == 4) ||(board[x][y].couleur == NOIR && x == 0 && y == 4))) {
        if (board[x][y+3].test_roquable==1 && board[x][y+1].type == PAS_DE_PIECE && board[x][y+2].type == PAS_DE_PIECE  && !RoiEnEchec_player(x,y+1,couleur,board,xRoiEnnemie,yRoiEnnemie) && !RoiEnEchec_player(x,y+2,couleur,board,xRoiEnnemie,yRoiEnnemie) ) {
            //printf("petit roque possible\n");
            ajout_deplacement(-2, y ,x , y+3,deplacements,nombreDeplacements );
        }
        if (board[x][y-4].test_roquable==1 && board[x][y-1].type == PAS_DE_PIECE && board[x][y-2].type == PAS_DE_PIECE && board[x][y-3].type == PAS_DE_PIECE && !RoiEnEchec_player(x,y-1,couleur,board,xRoiEnnemie,yRoiEnnemie) && !RoiEnEchec_player(x,y-2,couleur,board,xRoiEnnemie,yRoiEnnemie)) {
            //printf("grand roque possible\n");
            ajout_deplacement(-3, y ,x , y-4,deplacements,nombreDeplacements );
        }
    }
    

    
}



void ajouterDeplacementDame(int x, int y, int xRoi, int yRoi, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]) {
    // complexité à gagner en regroupant certain if
    int cloue = piece_cloue(x,y,xRoi,yRoi,board);

    // boucle pour trouver les déplacements vers le haut
    if (cloue == 0 || cloue == 1)
    {
        for (int i = x - 1; i >= 0; i--) {
            if (board[i][y].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,i , y,deplacements,nombreDeplacements ); 
            } else {
                if (board[i][y].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,i , y,deplacements,nombreDeplacements ); 
                }
                break;
            }
        }
        // boucle pour trouver les déplacements vers le bas
        for (int i = x + 1; i < 8; i++) {
            if (board[i][y].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,i , y,deplacements,nombreDeplacements ); 
            } else {
                if (board[i][y].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,i , y,deplacements,nombreDeplacements ); 
                }
                break;
            }
        }
    }
    if (cloue == 0 || cloue == 2)
    {
        // boucle pour trouver les déplacements vers la gauche
        for (int j = y - 1; j >= 0; j--) {
            if (board[x][j].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,x , j,deplacements,nombreDeplacements ); 
            } else {
                if (board[x][j].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,x , j,deplacements,nombreDeplacements ); 
                }
                break;
            }
        }
        // boucle pour trouver les déplacements vers la droite
        for (int j = y + 1; j < 8; j++) {
            if (board[x][j].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,x , j,deplacements,nombreDeplacements ); 
            } else {
                if (board[x][j].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,x , j,deplacements,nombreDeplacements ); 
                }
                break;
            }
        }
    }

    int i, j;
    if (cloue == 0 || cloue == 4)
    {
        for (i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++) {
            if (board[i][j].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
            } else {
                if (board[i][j].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
                }
                break;
            }
        }
        for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
            } else {
                if (board[i][j].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
                }
                break;
            }
        }
    }
    if (cloue == 0 || cloue == 3)
    {
        for (i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--) {
            if (board[i][j].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
            } else {
                if (board[i][j].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
                }
                break;
            }
        }
        for (i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++) {
            if (board[i][j].type == PAS_DE_PIECE) {
                ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
            } else {
                if (board[i][j].couleur != board[x][y].couleur) {
                    ajout_deplacement(x, y ,i , j,deplacements,nombreDeplacements );
                }
                break;
            }
        }
    }

}



int trouverRoi(int couleur, struct Piece board[8][8])
{
    for (int x = 0 ; x<8 ; x++ )
        for (int y = 0 ; y<8 ; y++ )
            if (board[x][y].type == ROI && board[x][y].couleur == couleur)
                return x*10+y;
    //affichePlateau(board);
    //sleep(100);
    perror("trouverRoi");

}



void __interception(int i, int j,int x, int y, int xRoi, int yRoi,struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8] )
{
    //printf("test __interception1 %d %d %d %d %d %d\n",i,j,x,y,xRoi,yRoi);
    int cloue = piece_cloue(i, j, xRoi,yRoi,board);

        if (cloue == 0 )
        {
            //printf("test3 %d %d %d %d \n", i, j,x, y);
            ajout_deplacement(i, j ,x , y,deplacements,nombreDeplacements );
            //printf("test12\n");
        }
}







void interception(int x,int y,int xRoi, int yRoi,struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8],int couleur)
{
    // couleur == a la couleur de la pièce qui fait échec
    //printf("test6 %d %d\n",x,y);
    int i;
    int j;
    int posX; 
    int posY;



    if (board[x][y].type != PAS_DE_PIECE)
    {
        //printf("test: %d %d %d \n", couleur, x,y);
        if (couleur == NOIR)
        {
            i = x-1;
            j = y-1;
            //printf("test4  \n" );
            if (i >= 0 && j >= 0 && board[i][j].type == PION && board[i][j].couleur == NOIR)
            {
                __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
            i = x-1;
            j = y+1;
            if (i >= 0 && j < 8 && board[i][j].type == PION && board[i][j].couleur == NOIR)
            {
                __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            } 
        }
        else
        {
            //printf("test8 \n");
            i = x+1;
            j = y-1;
            if (i < 8 && j >= 0 && board[i][j].type == PION && board[i][j].couleur == BLANC)
            {
                //printf("test10 \n");
                __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
                //printf("test10 \n");
            }
            i = x+1;
            j = y+1;
            if (i < 8 && j < 8 && board[i][j].type == PION && board[i][j].couleur == BLANC)
            {
                //printf("test11 \n");
                __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
                //printf("test11 \n");
            }
            //printf("test9 \n");
        }

    }
    else
    {
        if (couleur != NOIR)
        {
            if ( x+1<8  &&  board[x+1][y].type == PION && board[x+1][y].couleur != NOIR)
            {
                __interception(x+1, y,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
            if ( x+2  == 6 &&  board[x+2][y].type == PION && board[x+2][y].couleur != NOIR)
            {
                __interception(x+2, y,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
            
        }
        else
        {
            if ( x-1>= 0 &&  board[x-1][y].type == PION  && board[x-1][y].couleur != BLANC)
            {
                __interception(x-1, y,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
            if ( x-2  == 1 &&  board[x-2][y].type == PION && board[x-2][y].couleur != BLANC)
            {
                __interception(x-2, y,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
        }
        
    }

    
    //printf("test7 \n");

    if (x - 2 >= 0) {
        if (y - 1 >= 0) {
            if (board[x - 2][y - 1].type == CAVALIER && board[x - 2][y - 1].couleur == couleur ) {

            __interception(x-2, y-1,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            
            }
        }
        if (y + 1 < 8) {
            if (board[x - 2][y + 1].type == CAVALIER && board[x - 2][y + 1].couleur == couleur) {
            __interception(x-2, y+1,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            
            
            }
        }
    }

    
    if (x + 2 < 8) {
        if (y - 1 >= 0) {
            if (board[x + 2][y - 1].type == CAVALIER && board[x + 2][y - 1].couleur == couleur) {
            __interception(x+2, y-1,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
        }
        if (y + 1 < 8) {
            if (board[x + 2][y + 1].type == CAVALIER && board[x + 2][y + 1].couleur == couleur) {
            __interception(x+2, y+1,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
        }
    }
    if (y - 2 >= 0) {
        if (x - 1 >= 0) {
            if (board[x - 1][y - 2].type == CAVALIER && board[x - 1][y - 2].couleur == couleur) {
            __interception(x-1, y-2,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
        }
        if (x + 1 < 8) {
            if (board[x + 1][y - 2].type == CAVALIER && board[x + 1][y - 2].couleur == couleur) {
            __interception(x+1, y-2,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
        }
    }
    if (y + 2 < 8) {
        if (x - 1 >= 0) {
            if (board[x - 1][y + 2].type == CAVALIER && board[x - 1][y + 2].couleur == couleur) {
            __interception(x-1, y+2,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
        }
        if (x + 1 < 8) {
            if (board[x + 1][y + 2].type == CAVALIER && board[x + 1][y + 2].couleur == couleur) {
            __interception(x+1, y+2,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
        }
        }
    }





    i = x+1;
    j = y+1;



    while(i < 8 && j < 8 && board[i][j].type == PAS_DE_PIECE)
    {
        i++;
        j++;
    }
    if (i < 8 && j < 8 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur == couleur)
    {
        __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
    }


    i = x-1;
    j = y-1;
    while(i >= 0 && j >= 0 && board[i][j].type == PAS_DE_PIECE)
    {
        i--;
        j--;
    }
    if (i >= 0 && j >= 0 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur == couleur)
    {
        __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
    }


    i = x-1;
    j = y+1;
    while(i >= 0 && j < 8 && board[i][j].type == PAS_DE_PIECE)
    {
        i--;
        j++;
    }
    if (i >= 0 && j < 8 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur == couleur)
    {
        __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
    }


    i = x+1;
    j = y-1;
    while(i < 8 && j >= 0 && board[i][j].type == PAS_DE_PIECE)
    {
        i++;
        j--;
    }
    if (i < 8 && j >= 0 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur == couleur)
    {
        __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
    }


    i = x+1;
    j = y;
    while(i < 8 && board[i][j].type == PAS_DE_PIECE)
    {
        i++;
    }
    if (i < 8 && (board[i][j].type == DAME || board[i][j].type == TOUR) && board[i][j].couleur == couleur)
    {
        __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
    }


    i = x-1;
    j = y;
    while(i >= 0 && board[i][j].type == PAS_DE_PIECE)
    {
        i--;
    }
    if (i >= 0 && (board[i][j].type == DAME || board[i][j].type == TOUR) && board[i][j].couleur == couleur)
    {
        __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
    }


    i = x;
    j = y+1;
    while(j < 8 && board[i][j].type == PAS_DE_PIECE)
    {
        j++;
    }
    if (j < 8 && (board[i][j].type == DAME || board[i][j].type == TOUR) && board[i][j].couleur == couleur)
    {
        __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
    }


    i = x;
    j = y-1;
    while(j >= 0 && board[i][j].type == PAS_DE_PIECE)
    {
        j--;
    }
    if (j >= 0 && (board[i][j].type == DAME || board[i][j].type == TOUR) && board[i][j].couleur == couleur)
    {
        __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
    }


}


void interception_global(int xMenace, int yMenace, int xRoi, int yRoi,struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8],int couleur)
{
    if (board[xMenace][yMenace].type == CAVALIER || board[xMenace][yMenace].type == PION)
    {
        interception(xMenace,yMenace,xRoi,yRoi,deplacements,nombreDeplacements,board,couleur);
        return;
    }
    
    int i = xMenace;
    int j = yMenace;
    if (xRoi == xMenace)
    {
        if(yRoi > yMenace)
        {
            //j = yMenace+1;
            while(j != yRoi)
            {
                interception(i,j,xRoi,yRoi,deplacements,nombreDeplacements,board,couleur);
                j++;
            }
        }
        else
        {
            //j = yMenace-1;
            while(j != yRoi)
            {
                interception(i,j,xRoi,yRoi,deplacements,nombreDeplacements,board,couleur);
                j--;
            }
        }
        return;
    }
    if(yRoi == yMenace)
    {
        if(xRoi > xMenace)
        {
            //i = xMenace+1;
            while(i != xRoi)
            {
                
                interception(i,j,xRoi,yRoi,deplacements,nombreDeplacements,board,couleur);
                i++;
            }
        }
        else
        {
            //i = xMenace-1;
            while(i != xRoi)
            {
                
                interception(i,j,xRoi,yRoi,deplacements,nombreDeplacements,board,couleur);
                i--;
            }
        }
        return;
    }
    if(board[xMenace][yMenace].type == CAVALIER)
    {
        interception(xMenace,yMenace,xRoi,yRoi,deplacements,nombreDeplacements,board,couleur);
        return;
    }
    if(xMenace-xRoi == yMenace-yRoi)
    {
        if(xRoi > xMenace)
        {
            //i = xMenace+1;
            //j = yMenace+1;
            while(i != xRoi)
            {
                interception(i,j,xRoi,yRoi,deplacements,nombreDeplacements,board,couleur);
                i++;
                j++;
            }
        }
        else
        {
            //i = xMenace-1;
            //j = yMenace-1;
            while(i != xRoi)
            {
                interception(i,j,xRoi,yRoi,deplacements,nombreDeplacements,board,couleur);
                i--;
                j--;
            }
        }
        return;
    }
    if(xMenace-xRoi == -(yMenace-yRoi))
    {
        if(xRoi > xMenace)
        {
            //i = xMenace+1;
            //j = yMenace-1;
            while(i != xRoi)
            {
                interception(i,j,xRoi,yRoi,deplacements,nombreDeplacements,board,couleur);
                i++;
                j--;
            }
        }
        else
        {
            //i = xMenace-1;
            //j = yMenace+1;
            while(i != xRoi)
            {
                interception(i,j,xRoi,yRoi,deplacements,nombreDeplacements,board,couleur);
                i--;
                j++;
            }
        }
        return;
    }
    
}

void ajouterDeplacementsPossibles( int couleur, struct Deplacement deplacements[], int* nombreDeplacements, struct Piece board[8][8]) {
    int coord = trouverRoi(couleur,board);
    int xRoi = coord/10;
    int yRoi = coord%10;
    /*

    int echec = RoiEnEchec_bot(xRoi,yRoi,board);


    if (echec == -2)
    {
        ajouterDeplacementRoi(xRoi, yRoi, deplacements, nombreDeplacements, board);
        return;
    }
    if (echec != -1)
    {
        int ennemiex = echec/10;
        int ennemiey = echec%10;
        interception(ennemiex,ennemiey,xRoi , yRoi,deplacements, nombreDeplacements, board,couleur);
        if (ennemiex == xRoi)
        {
            
        }
        
        

        return;
    }

    */
    for (int x = 0 ; x<8 ; x++ )
    {
        for (int y = 0 ; y<8 ; y++ )
        {
            if (board[x][y].couleur == couleur)
            {
                switch(board[x][y].type) {
                    case PION:
                        ajouterDeplacementPion(x, y, xRoi, yRoi, deplacements, nombreDeplacements, board);
                        break;
                    case CAVALIER:
                        ajouterDeplacementCavalier(x, y,xRoi, yRoi, deplacements, nombreDeplacements, board);
                        break;
                    case FOU:
                        ajouterDeplacementFou(x, y,xRoi, yRoi, deplacements, nombreDeplacements, board);
                        break;
                    case TOUR:
                        ajouterDeplacementTour(x, y,xRoi, yRoi, deplacements, nombreDeplacements, board);
                        break;
                    case DAME:
                        ajouterDeplacementDame(x, y,xRoi, yRoi, deplacements, nombreDeplacements, board);
                        break;
                    case ROI:
                        ajouterDeplacementRoi(x, y, deplacements, nombreDeplacements, board);
                        break;
                    case PAS_DE_PIECE:
                        printf("pas de piece");
                        break;
                    default:
                        //printf("%i  %i\n",x,y);
                        //perror("ajouterDeplacementsPossibles");
                    }
            
            }
        }
    }

    
}


void initialiserPlateau(struct Piece plateau[8][8], char* fen) {
    int i = 0, j = 0, k = 0;
    while (fen[k] != ' ') {
        if (fen[k] >= '1' && fen[k] <= '8') {
            
            for(int y = j; y < j+fen[k]-'0' ;  y++ ) {
                plateau[i][y].type = PAS_DE_PIECE;
                plateau[i][y].couleur = -1;
		        plateau[i][y].name = ' ';
                plateau[i][y].test_roquable = 0;
            }
            
            j += fen[k] - '0';
        } else if (fen[k] == '/') {
            i++;
            j = 0;
        } else {
            if (fen[k]  <= 'z' && fen[k]  >= 'a')
            {
                plateau[i][j].type = (fen[k] == 'p') ? PION : (fen[k] == 'n') ? CAVALIER : (fen[k] == 'b') ? FOU : (fen[k] == 'r') ? TOUR : (fen[k] == 'q') ? DAME : ROI;
                plateau[i][j].couleur = (fen[k] < 'a') ? 1 : 0;
                plateau[i][j].name = fen[k] - 'a' + 'A';
                plateau[i][j].test_roquable = 1;
                ////printf("test 66 %c \n", fen[k]);
                j++;
            }
            else
            {
                plateau[i][j].type = (fen[k] == 'P') ? PION : (fen[k] == 'N') ? CAVALIER : (fen[k] == 'B') ? FOU : (fen[k] == 'R') ? TOUR : (fen[k] == 'Q') ? DAME : ROI;
                plateau[i][j].couleur = (fen[k] < 'a') ? 1 : 0;
                plateau[i][j].name = fen[k];
                plateau[i][j].test_roquable = 1;
                ////printf("test 55 %c \n", fen[k]);
                j++;
            }
            
            
            
        }

        k++;
    }
    int couleur;
    k++;
    if (fen[k] == 'w')
        couleur = BLANC;
    else 
        couleur = NOIR;
    
    k++;
    int Roi = trouverRoi(couleur,plateau);
    int xRoiBlanc = Roi/10;
    int yRoiBlanc = Roi%10;

    Roi = trouverRoi(couleur,plateau);
    int xRoiNoir = Roi/10;
    int yRoiNoir = Roi%10;

    while(fen[k] != '-' && fen[k] != ' ')
    {
        if(fen[k] == 'K')
        {
            plateau[xRoiBlanc][yRoiBlanc].test_roquable = 1;
            plateau[xRoiBlanc][yRoiBlanc+3].test_roquable = 1;
        }
        else if(fen[k] == 'Q')
        {
            plateau[xRoiBlanc][yRoiBlanc].test_roquable = 1;
            plateau[xRoiBlanc][yRoiBlanc-4].test_roquable = 1;
        }
        else if(fen[k] == 'k')
        {
            plateau[xRoiNoir][yRoiNoir].test_roquable = 1;
            plateau[xRoiNoir][yRoiNoir+3].test_roquable = 1;
        }
        else if(fen[k] == 'q')
        {
            plateau[xRoiNoir][yRoiNoir].test_roquable = 1;
            plateau[xRoiNoir][yRoiNoir-4].test_roquable = 1;
        }
        k++;
    }

}

void roi_mange_menace(int xmenace,int ymenace,int xRoi,int yRoi,struct Deplacement* deplacements,int* nbDeplacements,struct Piece board[8][8],int couleur )
{
    int positionEnnemie = trouverRoi(!couleur,board);
    int xRoiEnnemie = positionEnnemie/10;
    int yRoiEnnemie = positionEnnemie%10;
    if ((xmenace-1 == xRoi || xmenace == xRoi || xmenace+1 == xRoi) && (ymenace-1 == yRoi || ymenace == yRoi || ymenace+1 == yRoi))
    {
        if (RoiEnEchec_player(xmenace,ymenace,couleur,board,xRoiEnnemie, yRoiEnnemie) == 0)
        {
            ajout_deplacement(xRoi, yRoi ,xmenace , ymenace,deplacements,nbDeplacements);
        }

    }

}

void deplacementsPossibles(int couleur,struct Deplacement* deplacements, int* nbDeplacements,  struct Piece board[8][8] )
{
    int Roi = trouverRoi(couleur,board);
    int xRoi = Roi/10;
    int yRoi = Roi%10;
    int menace = RoiEnEchec_bot(xRoi,yRoi,board);
    if (menace == -1)
        ajouterDeplacementsPossibles(couleur, deplacements, nbDeplacements, board);
    else
    {
        if (menace != -2){
            interception_global(menace/10,menace%10,xRoi,yRoi,deplacements, nbDeplacements,board,couleur );
            roi_mange_menace(menace/10,menace%10,xRoi,yRoi,deplacements, nbDeplacements,board,couleur );
        }
        ajouterDeplacementRoi(xRoi,yRoi,deplacements,nbDeplacements,board);
    }

    //afficheDeplacements(deplacements,*nbDeplacements);
}


int estPresent(struct Deplacement deplacement, struct Deplacement listeDeplacements[], int n) {
    for (int i = 0; i < n; i++) {
        if (deplacement.xDepart < 0 && listeDeplacements[i].xDepart == deplacement.xDepart)
        {
            return 1;
        }
        
        //printf("\n%c%c %c%c\n", listeDeplacements[i].xDepart,listeDeplacements[i].yDepart, listeDeplacements[i].xArrivee, listeDeplacements[i].yArrivee );
        if (deplacement.xDepart == listeDeplacements[i].xDepart &&
            deplacement.yDepart == listeDeplacements[i].yDepart &&
            deplacement.xArrivee == listeDeplacements[i].xArrivee &&
            deplacement.yArrivee == listeDeplacements[i].yArrivee) {
            return 1;
        }
    }
    return 0;
}


void mettre_la_case_a_vide(int x,int y,struct Piece board[8][8])
{
    board[x][y].couleur = -1;
    board[x][y].type = PAS_DE_PIECE;
    board[x][y].name = ' ';
    board[x][y].test_roquable = 0;
}


void movePiece(struct Deplacement deplacement, struct Piece board[8][8], int couleur)
{
    if (deplacement.xDepart == -2)
    {
        if (couleur == BLANC)
        {
            board[7][6] = board[7][4];
            board[7][5] = board[7][7];
            //printf("salut\n");
            mettre_la_case_a_vide(7,4,board);
            mettre_la_case_a_vide(7,7,board);
            board[7][6].test_roquable = 0;

        }
        else
        {
            board[0][6] = board[0][4];
            board[0][5] = board[0][7];

            mettre_la_case_a_vide(0,4,board);
            mettre_la_case_a_vide(0,7,board);
            board[0][6].test_roquable = 0;
        }
        return;
    }
    if (deplacement.xDepart == -3)
    {
        if (couleur == BLANC)
        {
            board[7][2] = board[7][4];
            board[7][3] = board[7][0];

            board[7][2].test_roquable = 0;
            mettre_la_case_a_vide(7,4,board);
            mettre_la_case_a_vide(7,0,board);

        }
        else
        {
            board[0][2] = board[0][4];
            board[0][3] = board[0][0];
            board[0][2].test_roquable = 0;
            mettre_la_case_a_vide(0,4,board);
            mettre_la_case_a_vide(0,0,board);
        }
        return;
    }
    if (board[deplacement.xDepart][deplacement.yDepart].type == PION && (deplacement.xArrivee == 0 || deplacement.xArrivee == 7))
    {
        //board[deplacement.xArrivee][deplacement.yArrivee] = board[deplacement.xDepart][deplacement.yDepart];
        board[deplacement.xArrivee][deplacement.yArrivee].couleur  = board[deplacement.xDepart][deplacement.yDepart].couleur;
        if (couleur == BLANC)
        {
            board[deplacement.xArrivee][deplacement.yArrivee].name = 'Q';
        }
        else
        {
            board[deplacement.xArrivee][deplacement.yArrivee].name = 'q';
        }
        board[deplacement.xArrivee][deplacement.yArrivee].type = DAME;
        mettre_la_case_a_vide(deplacement.xDepart,deplacement.yDepart,board);
        return;
    }
    
    board[deplacement.xArrivee][deplacement.yArrivee] = board[deplacement.xDepart][deplacement.yDepart];
    board[deplacement.xDepart][deplacement.yDepart].couleur = -1;
    board[deplacement.xDepart][deplacement.yDepart].type = PAS_DE_PIECE;
    board[deplacement.xDepart][deplacement.yDepart].name = ' ';
    board[deplacement.xArrivee][deplacement.yArrivee].test_roquable = 0;
    board[deplacement.xDepart][deplacement.yDepart].test_roquable = 0;

}
/*
int* dead_pieces(struct Piece board[8][8], int couleur){
    int *result = malloc(7);
    for(int y = 0; y<8; y++)
        for(int x = 0; x<8; x++)
            if(board[y][x].couleur == couleur && board[y][x].type != PAS_DE_PIECE)
                result[board[y][x].type]++;
    return result;
}
*/




void position_precedante(struct Piece board[8][8],struct Piece manger,struct Piece deplacer,struct Deplacement deplacement)
{
    if (deplacement.xDepart == -2 )
    {
        if (deplacer.couleur == NOIR)
        {
            board[0][4] = board[0][6];
            board[0][7] = board[0][5];
            mettre_la_case_a_vide(0,6,board);
            mettre_la_case_a_vide(0,5,board);
        }
        else
        {
            board[7][4] = board[7][6];
            board[7][7] = board[7][5];
            mettre_la_case_a_vide(7,6,board);
            mettre_la_case_a_vide(7,5,board);
        }
        
    }
    else if (deplacement.xDepart == -3)
    {
        if (deplacer.couleur == NOIR)
        {
            board[0][0] = board[0][3];
            board[0][4] = board[0][2];
            mettre_la_case_a_vide(0,2,board);
            mettre_la_case_a_vide(0,3,board);
        }
        else
        {
            board[7][0] = board[7][3];
            board[7][4] = board[7][2];
            mettre_la_case_a_vide(7,2,board);
            mettre_la_case_a_vide(7,3,board);
        }
    }
    else
    {
        board[deplacement.xDepart][deplacement.yDepart] = deplacer;
        board[deplacement.xArrivee][deplacement.yArrivee] = manger;
    }
    
}



// Structure pour les arguments du thread
struct ThreadArgs {
    int tours_restant;
    int couleur;
    int IA_Couleur;
    struct Piece board[8][8];
    float result;
};
/*
struct ThreadArgs2 {
    int tours_restant;
    int couleur;
    struct Piece board[8][8];
    struct Deplacement result;
};
*/


float fmin2(float a, float b) {
    return a < b ? a : b;
}

float fmax2(float a, float b) {
    return a > b ? a : b;
}

int inverse(int couleur) {
    return (couleur == BLANC) ? NOIR : BLANC;
}


void copy_board(struct Piece dest[8][8], struct Piece src[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            src[i][j].couleur = dest[i][j].couleur;
            src[i][j].name = dest[i][j].name;
            src[i][j].test_roquable = dest[i][j].test_roquable;
            src[i][j].type = dest[i][j].type;
        }
    }
}


float protege_par_pion(struct Piece board[8][8],int x, int y, int couleur)
{

    if (couleur == BLANC && (case_existe(x-1,y-1) && board[x-1][y-1].type == PION && board[x-1][y-1].couleur == BLANC || (case_existe(x-1,y+1) && board[x-1][y+1].type == PION && board[x-1][y+1].couleur == BLANC)) )
    {
        return 0.15;
    }
    if (couleur == NOIR && (case_existe(x+1,y-1) && board[x+1][y-1].type == PION && board[x+1][y-1].couleur == NOIR || (case_existe(x+1,y+1) && board[x+1][y+1].type == PION && board[x+1][y+1].couleur == NOIR)) )
    {
        return 0.15;
    }
    return 0;
}

float calculer_position_pion(struct Piece board[8][8],int x, int y, int couleur)
{
    float score = 0.0;


    // rajoute des point ou pion qui est plus au centre
    float tab[8] = { -0.1 , 0 , 0.05 , 0.1 , 0.1 , 0.05 , 0 , -0.1 };

    score += tab[y];


    // rajoute des point si une pion est dans le carée centrale

    int centre[4][2] = {{3, 3}, {3, 4}, {4, 3}, {4, 4}};

    for (size_t i = 0; i < 4; i++)
    {
        if (x == centre[i][0] && y == centre[i][1]) 
        {
            //printf("pion au centre\n");
            score += 0.15;
            break;
        }
    }
    

    // diminie les score si la pièce est doubler ou plus.
    for (size_t i = 0; i < 8; i++)
    {
        if (i != x && board[i][y].type == PION && board[i][y].couleur == couleur)
        {
            //printf("pion doubler\n");
            score -= 0.2;
        }
        
    }
    // Pion passer

    //int estPionPasse = 1; // Variable pour vérifier si le pion est passé
    if (couleur == BLANC)
    {
        for (int i = x - 1; i >= 0; i--) {
            if(board[i][y].type != PAS_DE_PIECE && (board[i][y].couleur != couleur || board[i][y].couleur == couleur && board[i][y].type == PION))
            {
                return score;
            }
        }
        if(y-1 >= 0)
        {
            for (int i = x - 1; i >= 0; i--) {
                if(board[i][y-1].type != PAS_DE_PIECE && board[i][y-1].couleur != couleur)
                {
                    return score;
                }
            }
        }
        if(y+1 < 8)
        {
            for (int i = x - 1; i >= 0; i--) {
                if(board[i][y+1].type != PAS_DE_PIECE && board[i][y+1].couleur != couleur)
                {
                    return score;
                }
            }
        }  
    }
    else
    {
        for (int i = x + 1; i >= 0; i++) {
            if(board[i][y].type != PAS_DE_PIECE && (board[i][y].couleur != couleur || board[i][y].couleur == couleur && board[i][y].type == PION))
            {
                return score;
            }
        }
        if(y-1 >= 0)
        {
            for (int i = x + 1; i >= 0; i++) {
                if(board[i][y-1].type != PAS_DE_PIECE && board[i][y-1].couleur != couleur)
                {
                    return score;
                }
            }
        }
        if(y+1 < 8)
        {
            for (int i = x + 1; i >= 0; i++) {
                if(board[i][y+1].type != PAS_DE_PIECE && board[i][y+1].couleur != couleur)
                {
                    return score;
                }
            }
        }
    }
    float tab2[8] = {0.0,0.1,0.1,0.2,0.4,1.0,3.0,0.0};

    if (couleur == BLANC)
    {
        return score + tab2[7-x];
    }
    else
    {
        return score + tab2[x];
    }
    
    
    /*
    // Pion passer
    int estPionPasse = 1; // Variable pour vérifier si le pion est passé
    if (couleur == BLANC)
    {

        for (int i = x - 1; i >= 0; i--) {
            if (i >= 0 && i < 8 && i != y) {
                if (board[i][y].type == PION && board[i][y].couleur != couleur && (y+1 < 8 || (board[i][y+1].type == PION && board[i][y+1].couleur != couleur))&& (y-1 > 0 || (board[i][y-1].type == PION && board[i][y-1].couleur != couleur))) {
                    estPionPasse = 0;
                    break;
                }
            }
        }
        
    }
    else
    {

        for (int i = x + 1; i <= 7; i++) {
            if (i >= 0 && i < 8 && i != y) {
                if (board[i][y].type == PION && board[i][y].couleur != couleur && (y+1 < 8 || (board[i][y+1].type == PION && board[i][y+1].couleur != couleur))&& (y-1 > 0 || (board[i][y-1].type == PION && board[i][y-1].couleur != couleur))) {
                    estPionPasse = 0;
                    break;
                 }
             }
          }
        
    }
    

    if (estPionPasse) {
        // Le pion est passé, ajustez le score en conséquence
        score += 0.5;
    }
    */
    //return score;
}


float calculer_position_cavalier(struct Piece board[8][8],int x, int y, int couleur)
{
    float score = 0.0;

    if (x == 0 || x == 7 || y == 0 || y ==7)
    {
        score -= 0.15;
    }
    return score;
}


float calculer_position_tour(struct Piece board[8][8],int x, int y, int couleur)
{
    float score = 0.0;




    // deux tour sont conecter


    for (size_t i = x+1; i < 8; i++)
    {
        if (board[i][y].type == PAS_DE_PIECE)
        {
            continue;
        }
        
        if (board[i][y].type == TOUR && board[i][y].couleur == couleur)
        {
            score += 0.15;
        }
        break;
    }
    for (size_t i = x-1; i >= 0; i--)
    {
        if (board[i][y].type == PAS_DE_PIECE)
        {
            continue;
        }
        
        if (board[i][y].type == TOUR && board[i][y].couleur == couleur)
        {
            score += 0.15;
        }
        break;
    }
    for (size_t i = y+1; i < 8; i++)
    {
        if (board[x][i].type == PAS_DE_PIECE)
        {
            continue;
        }
        
        if (board[x][i].type == TOUR && board[x][i].couleur == couleur)
        {
            score += 0.15;
        }
        break;
    }
    for (size_t i = y-1; i >= 0; i--)
    {
        if (board[x][i].type == PAS_DE_PIECE)
        {
            continue;
        }
        
        if (board[x][i].type == TOUR && board[x][i].couleur == couleur)
        {
            score += 0.15;
        }
        break;
    }
    


    // rajoute des point si la colone de la tour est ouverte ou semi-ouverte
    


    int pion_enemie = 0;
    int pion_amie = 0;

    for (size_t i = 0; i < 8; i++)
    {
        
        
        if (board[i][y].type == PION)
        {
            if (board[i][y].couleur == board[x][y].couleur)
            {
                pion_amie = 1;
            }
            else
            {
                pion_enemie = 1;
            }
            
        }
        
    }
    if (pion_amie == 0)
    {
        if (pion_enemie = 0)
        {
            //printf("colone ouverte\n");
            score += 0.3;
        }
        else
        {
            //printf("colone semie-ouverte\n");
            score += 0.15;
        }
        
    }
    
    
    // la tour est dans la 7 ème ranger

    if (y == 1 && couleur == BLANC || y == 7 && couleur == NOIR)
    {
        score += 0.35;
    }
    
    

    return score;
}


float calculer_position_fou(struct Piece board[8][8],int x, int y, int couleur)
{
    float score = 0.0;

    if (x == 0 && y == 2 && couleur == NOIR)
    {
        if(board[1][1].couleur == NOIR && board[1][3].couleur == NOIR)
            score -= 0.4;
        else
            score -= 0.2;
    }
    else if (x == 0 && y == 5 && couleur == NOIR)
    {
        if(board[1][4].couleur == NOIR && board[1][6].couleur == NOIR)
            score -= 0.4;
        else
            score -= 0.2;
    }

    else if (x == 7 && y == 2 && couleur == BLANC)
    {
        if(board[6][1].couleur == BLANC && board[6][3].couleur == BLANC)
            score -= 0.4;
        else
            score -= 0.2;
    }
    else if (x == 7 && y == 5 && couleur == BLANC)
    {
        if(board[6][4].couleur == BLANC && board[6][6].couleur == BLANC)
            score -= 0.4;
        else
            score -= 0.2;
    }

    return score;
}



float calculer_position_roi(struct Piece board[8][8],int x, int y, int couleur)
{
    float score = 0.0;

    if((x == 0 && y == 2 && couleur == NOIR && board[0][0].type != TOUR && board[0][1].type != TOUR) || (x == 0 && y == 6 && couleur == NOIR && board[0][7].type != TOUR && board[0][6].type != TOUR))
    {
        score += 0.4;
    }
    else if((x == 7 && y == 2 && couleur == BLANC && board[7][0].type != TOUR && board[7][1].type != TOUR) || (x == 7 && y == 6 && couleur == BLANC && board[7][7].type != TOUR && board[7][6].type != TOUR))
    {
        score += 0.4;
    }
    if ((x == 0 && y == 3 && couleur == NOIR &&  (board[0][0].type == TOUR || board[0][1].type == TOUR  || board[0][2].type == TOUR )) ||(x == 0 && y == 5 && couleur == NOIR &&  (board[0][6].type == TOUR || board[0][7].type == TOUR  )))
    {
        score -= 0.3;
    }
    if ((x == 7 && y == 3 && couleur == BLANC &&  (board[7][0].type == TOUR || board[7][1].type == TOUR  || board[7][2].type == TOUR )) ||(x == 7 && y == 5 && couleur == NOIR &&  (board[7][6].type == TOUR || board[7][7].type == TOUR  )))
    {
        score -= 0.3;
    }
    return score;
}

float calculer_score(struct Piece board[8][8], int joueur) {
    float score = 0.0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            struct Piece piece = board[i][j];
            if (piece.type == PAS_DE_PIECE) {
                continue;
            }
            float valeur = 0.0;
            switch (piece.type) {
                case PION:
                    valeur = 1.0 + calculer_position_pion(board,i,j,piece.couleur) +0.5 * protege_par_pion(board,i,j,piece.couleur);
                    break;
                case CAVALIER:
                    valeur = 3.0 +  calculer_position_cavalier(board,i,j,piece.couleur)+ protege_par_pion(board,i,j,piece.couleur);
                    break;
                case FOU:
                    valeur = 3.25 + calculer_position_fou(board,i,j,piece.couleur)+ protege_par_pion(board,i,j,piece.couleur);
                    break;
                case TOUR:
                    valeur = 5.0 +  calculer_position_tour(board,i,j,piece.couleur);
                    break;
                case DAME:
                    valeur = 9.0;
                    break;
                case ROI:
                    valeur = 100.0 + calculer_position_roi(board,i,j,piece.couleur);
                    break;
            }
            if (piece.couleur == joueur) {
                score += valeur;
            } else {
                score -= valeur;
            }
        }
    }
    //return score;
    return (joueur == 1) ? score : -score;
}


float calculer_score_V2(struct Piece board[8][8], int joueur) {
    float score = 0.0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            struct Piece piece = board[i][j];
            if (piece.type == PAS_DE_PIECE)
                continue;
            float valeur = 0.0;
            switch (piece.type) {
                case PION:
                    valeur = 1.0;
                    break;
                case CAVALIER:
                    valeur = 3.0;
                    break;
                case FOU:
                    valeur = 3.0;
                    break;
                case TOUR:
                    valeur = 5.0;
                    break;
                case DAME:
                    valeur = 9.0;
                    break;
                case ROI:
                    valeur = 100.0;
                    break;
            }
            if (piece.couleur == joueur)
                score += valeur;
            else
                score -= valeur;
        }
    }
    //return score;
    return (joueur == 1) ? score : -score;
}





float minmax_ancien(int tours_restant, int couleur,int IA_Couleur, struct Piece board[8][8]) {
    pthread_testcancel();
    if (tours_restant <= 0) {
        float s = calculer_score(board, couleur);
        //affichePlateau(board);
        //printf("les score est: %f\n",s);
        //affichePlateau(board);
        //printf("les score est: %f\n",s);
        if(IA_Couleur == NOIR)
            s = s*(-1);
        return s;
    }
    
    struct Deplacement deplacements[100];
    int nombreDeplacements =0 ;
    deplacementsPossibles(couleur, deplacements, &nombreDeplacements, board);
    //printf("le nombre de deplacement %i\n",nombreDeplacements);
    //afficheDeplacements( deplacements, nombreDeplacements, board);
    if (nombreDeplacements == 0) {
        return (couleur == IA_Couleur) ? -9999 : 9999; // si le joueur ne peut pas bouger, retourner un score très bas (pour le joueur blanc) ou très haut (pour le joueur noir)
    }
    
    float score = (couleur == IA_Couleur) ? -9999 : 9999; // initialiser score à un score très bas (pour le joueur blanc) ou très haut (pour le joueur noir)
    for (int i = 0; i < nombreDeplacements; i++) {
        struct Piece board2[8][8];
        copy_board(board, board2); // copier le tableau board dans board2
        //struct Piece manger = board[deplacements[i].xArrivee][deplacements[i].yArrivee];
        //struct Piece deplacer = board[deplacements[i].xDepart][deplacements[i].yDepart];
        movePiece(deplacements[i], board2, couleur);

        
        float score_children = minmax_ancien(tours_restant - 1, inverse(couleur),IA_Couleur, board2);
        //position_precedante(board,manger,deplacer,deplacements[i]);
        score = (couleur == IA_Couleur) ? fmax2(score, score_children) : fmin2(score, score_children); // utiliser la fonction max ou min en fonction de la couleur du joueur
    }

    return score;
}
/*
float alphabeta(int tours_restants, int PROFONDEUR_ATTENTE, int couleur, int IA_Couleur, struct Piece board[8][8], float alpha, float beta) {
    pthread_testcancel();
    if (tours_restants <= 0) {
        float s = calculer_score(board, couleur);
        if (IA_Couleur == NOIR)
            s = -s;
        return s;
    }
    
    struct Deplacement deplacements[100];
    int nombreDeplacements = 0;
    deplacementsPossibles(couleur, deplacements, &nombreDeplacements, board);
    
    if (nombreDeplacements == 0) {
        return (couleur == IA_Couleur) ? -9999 : 9999;
    }
    
    struct Piece manger;
    struct Piece deplacer;
    
    if (tours_restants <= PROFONDEUR_ATTENTE) {
        // Ne pas effectuer d'élagage Alpha-Bêta si la profondeur est inférieure à PROFONDEUR_ATTENTE
        for (int i = 0; i < nombreDeplacements; i++) {
            manger = board[deplacements[i].xArrivee][deplacements[i].yArrivee];
            deplacer = board[deplacements[i].xDepart][deplacements[i].yDepart];
            if (deplacements[i].xDepart < 0) {
                deplacer.couleur = couleur;
            }
            
            movePiece(deplacements[i], board, couleur);

            
            float score_children = alphabeta(tours_restants - 1,PROFONDEUR_ATTENTE, inverse(couleur), IA_Couleur, board, -beta, -alpha);
            //position_precedente(board, manger, deplacer, deplacements[i]);
            position_precedante(board,manger,deplacer,deplacements[i]);
            //int score;
            //score = (couleur != IA_Couleur) ? fmax2(score, score_children) : fmin2(score, score_children);
            if (score_children >= beta) {
                return beta;
            }
            
            if (score_children > alpha) {
                alpha = score_children;
            }
        }
        
        return alpha;
    } else {
        // Effectuer l'élagage Alpha-Bêta pour les profondeurs plus profondes
        for (int i = 0; i < nombreDeplacements; i++) {
            manger = board[deplacements[i].xArrivee][deplacements[i].yArrivee];
            deplacer = board[deplacements[i].xDepart][deplacements[i].yDepart];
            if (deplacements[i].xDepart < 0) {
                deplacer.couleur = couleur;
            }
            
            movePiece(deplacements[i], board, couleur);
            float bonus_roque = 0.0;
            if (deplacements[i].xDepart == -2 || deplacements[i].xDepart == -3) {
                bonus_roque = 1.0;
            }
            
            float score_children = alphabeta(tours_restants - 1,PROFONDEUR_ATTENTE, inverse(couleur), IA_Couleur, board, -beta, -alpha);
            position_precedante(board, manger, deplacer, deplacements[i]);
    
        
            if (score_children >= beta) {
                return beta;
            }
        
            if (score_children > alpha) {
                alpha = score_children;
            }
    }
    
    return alpha;
    }
}
*/


float alphabeta(int tours_restants, int PROFONDEUR_ATTENTE, int couleur, int IA_Couleur, struct Piece board[8][8], float alpha, float beta) {
    pthread_testcancel();
    if (tours_restants <= 0) {
        float s = calculer_score(board, couleur);
        if (IA_Couleur == NOIR)
            s = -s;
        return s;
    }
    
    struct Deplacement deplacements[100];
    int nombreDeplacements = 0;
    deplacementsPossibles(couleur, deplacements, &nombreDeplacements, board);
    
    if (nombreDeplacements == 0) {
        return (couleur == IA_Couleur) ? -9999 : 9999;
    }
    
    struct Piece manger;
    struct Piece deplacer;
    
    if (tours_restants <= PROFONDEUR_ATTENTE  ) {
        // Ne pas effectuer d'élagage Alpha-Bêta si la profondeur est inférieure à PROFONDEUR_ATTENTE
        for (int i = 0; i < nombreDeplacements; i++) {
            manger = board[deplacements[i].xArrivee][deplacements[i].yArrivee];
            deplacer = board[deplacements[i].xDepart][deplacements[i].yDepart];
            if (deplacements[i].xDepart < 0) {
                deplacer.couleur = couleur;
            }
            
            movePiece(deplacements[i], board, couleur);

            float score_children;
            
            if (couleur == IA_Couleur) {
                score_children = alphabeta(tours_restants - 1, PROFONDEUR_ATTENTE, inverse(couleur), IA_Couleur, board, alpha, beta);
                if (score_children >= beta) {
                    position_precedante(board,manger,deplacer,deplacements[i]);
                    return beta;
                }
                if (score_children > alpha) {
                    alpha = score_children;
                }
            } else {
                score_children = alphabeta(tours_restants - 1, PROFONDEUR_ATTENTE, inverse(couleur), IA_Couleur, board, alpha, beta);
                if (score_children <= alpha) {
                    position_precedante(board,manger,deplacer,deplacements[i]);
                    return alpha;
                }
                if (score_children < beta) {
                    beta = score_children;
                }
            }
            
            position_precedante(board,manger,deplacer,deplacements[i]);
        }
        
        if (couleur == IA_Couleur) {
            return alpha;
        } else {
            return beta;
        }
    } else {
        // Effectuer l'élagage Alpha-Bêta pour les profondeurs plus profondes
        for (int i = 0; i < nombreDeplacements; i++) {
            manger = board[deplacements[i].xArrivee][deplacements[i].yArrivee];
            deplacer = board[deplacements[i].xDepart][deplacements[i].yDepart];
            if (deplacements[i].xDepart < 0) {
                deplacer.couleur = couleur;
            }
            
            movePiece(deplacements[i], board, couleur);
            
            float score_children;
            
            if (couleur == IA_Couleur) {
                float bonus_roque = 0.0;
                if (deplacements[i].xDepart == -2 || deplacements[i].xDepart == -3) {
                    bonus_roque = 1.0;
                }
                
                score_children = alphabeta(tours_restants - 1, PROFONDEUR_ATTENTE, inverse(couleur), IA_Couleur, board, alpha, beta) - bonus_roque;
                
                if (score_children >= beta) {
                    position_precedante(board,manger,deplacer,deplacements[i]);
                    return beta;
                }
                if (score_children > alpha) {
                    alpha = score_children;
                }
            } else {
                score_children = alphabeta(tours_restants - 1, PROFONDEUR_ATTENTE, inverse(couleur), IA_Couleur, board, alpha, beta);
                
                if (score_children <= alpha) {
                    position_precedante(board,manger,deplacer,deplacements[i]);
                    return alpha;
                }
                if (score_children < beta) {
                    beta = score_children;
                }
            }
            
            position_precedante(board,manger,deplacer,deplacements[i]);
        }
        
        if (couleur == IA_Couleur) {
            return alpha;
        } else {
            return beta;
        }
    }
}






/*
float alphabeta(int tours_restants, int couleur, int IA_Couleur, struct Piece board[8][8], float alpha, float beta) {
    pthread_testcancel();
    if (tours_restants <= 0) {
        float s = calculer_score(board, couleur);
        if (IA_Couleur == NOIR)
            s = -s;
        return s;
    }
    
    struct Deplacement deplacements[100];
    int nombreDeplacements = 0;
    deplacementsPossibles(couleur, deplacements, &nombreDeplacements, board);
    
    if (nombreDeplacements == 0) {
        return (couleur == IA_Couleur) ? -9999 : 9999;
    }
    
    struct Piece manger;
    struct Piece deplacer;
    
    for (int i = 0; i < nombreDeplacements; i++) {
        manger = board[deplacements[i].xArrivee][deplacements[i].yArrivee];
        deplacer = board[deplacements[i].xDepart][deplacements[i].yDepart];
        if (deplacements[i].xDepart < 0) {
            deplacer.couleur = couleur;
        }
        
        movePiece(deplacements[i], board, couleur);

        
        float score_children = alphabeta(tours_restants - 1, inverse(couleur), IA_Couleur, board, -beta, -alpha);
        position_precedante(board, manger, deplacer, deplacements[i]);
        
        if (score_children >= beta) {
            return beta;
        }
        
        if (score_children > alpha) {
            alpha = score_children;
        }
    }
    
    return alpha;
}
*/
float minmax(int tours_restants,int PROFONDEUR_ATTENTE, int couleur, int IA_Couleur, struct Piece board[8][8]) {
    return alphabeta(tours_restants,PROFONDEUR_ATTENTE, couleur, IA_Couleur, board, -9999, 9999);
}









float minmax2(int tours_restant, int couleur,int IA_Couleur, struct Piece board[8][8]) {
    pthread_testcancel();
    if (tours_restant <= 0) {
        float s = calculer_score(board, couleur);
        //affichePlateau(board);
        //printf("les score est: %f\n",s);
        //affichePlateau(board);
        //printf("les score est: %f\n",s);
        if(IA_Couleur == NOIR)
            s = s*(-1);
        return s;
    }
    
    struct Deplacement deplacements[100];
    int nombreDeplacements =0 ;
    deplacementsPossibles(couleur, deplacements, &nombreDeplacements, board);
    //printf("le nombre de deplacement %i\n",nombreDeplacements);
    //afficheDeplacements( deplacements, nombreDeplacements, board);
    if (nombreDeplacements == 0) {
        return (couleur == IA_Couleur) ? -9999 : 9999; // si le joueur ne peut pas bouger, retourner un score très bas (pour le joueur blanc) ou très haut (pour le joueur noir)
    }
    struct Piece manger;
    struct Piece deplacer;
    float score = (couleur == IA_Couleur) ? -9999 : 9999; // initialiser score à un score très bas (pour le joueur blanc) ou très haut (pour le joueur noir)
    for (int i = 0; i < nombreDeplacements; i++) {
        //struct Piece board2[8][8];
        //copy_board(board, board2); // copier le tableau board dans board2


        manger = board[deplacements[i].xArrivee][deplacements[i].yArrivee];
        deplacer = board[deplacements[i].xDepart][deplacements[i].yDepart];
        if (deplacements[i].xDepart < 0)
        {
            deplacer.couleur = couleur;
        }
        
        
        movePiece(deplacements[i], board, couleur);
        /*
        float bonus_roque =0.0;
        if (deplacements[i].xDepart ==-2 || deplacements[i].xDepart == -3)
        {
            bonus_roque = 1.0;
        }
        */
        float score_children = minmax2(tours_restant - 1, inverse(couleur),IA_Couleur, board) ;
        position_precedante(board, manger, deplacer, deplacements[i]);
        score = (couleur == IA_Couleur) ? fmax2(score, score_children) : fmin2(score, score_children); // utiliser la fonction max ou min en fonction de la couleur du joueur
    }

    return score;
}
/*
void minmax_intermediaire(int tours_restant, int couleur, int IA_Couleur, struct Piece board[8][8], float* rep) {
    struct Piece board2[8][8];
    copy_board(board, board2);
    *rep = minmax(1, 2, couleur, IA_Couleur, board2);
    
    for (int i = 3; i < 100; i += 2) {
        copy_board(board, board2);
        *rep = minmax(tours_restant, i, couleur, IA_Couleur, board2);
        pthread_testcancel();

        if (i >= 5) {
            printf("Profondeur : %i\n", i);
        }
    }
}

*/

void minmax_intermediaire(int temps,int couleur, int IA_Couleur, struct Piece board[8][8], float* rep) {
    struct Piece board2[8][8];
    copy_board(board, board2);
    *rep = minmax(1, 2, couleur, IA_Couleur, board2);
    
    for (size_t i = 3; i < 100; i += 2) {
        copy_board(board, board2);
        
        if (i > 4) {
            *rep = minmax(i, i-2, couleur, IA_Couleur, board2);
        } else {
            *rep = minmax(i, 3, couleur, IA_Couleur, board2);
        }
        //printf("Profondeur : %i\n", i);
        
        pthread_testcancel();
        
        if (i >= 5) {
            //printf("Profondeur : %i\n", i);
        }
    }
}

/*
void minmax_intermediaire(int tours_restant, int couleur,int IA_Couleur, struct Piece board[8][8],float* rep) {
    struct Piece board2[8][8];
    copy_board(board, board2);
    *rep =  minmax(1,2,couleur,IA_Couleur,board2);
    for (size_t i = 1; i < 100; i+=2)
    {
        copy_board(board, board2);
        if(i > 4)
        {
            *rep =  minmax(i,i-2,couleur,IA_Couleur,board2);
        }
        else
        {
            *rep =  minmax(i,3,couleur,IA_Couleur,board2);
        }
        
        pthread_testcancel();
        if (i >= 5)
        {
            printf("profondeure de : %i\n",i);
        }

    }
}
*/
// Fonction exécutée par le thread
void* threadFunc(void* args) {
    struct ThreadArgs* threadArgs = (struct ThreadArgs*)args;
    minmax_intermediaire(threadArgs->tours_restant, threadArgs->couleur, threadArgs->IA_Couleur, threadArgs->board, &(threadArgs->result));
    return NULL;
}



// Fonction principale
struct Deplacement main_minmax(int tours_restant, int couleur, struct Piece board[8][8]) {
    struct Deplacement deplacements[100];
    int nombreDeplacements = 0;
    deplacementsPossibles(couleur, deplacements, &nombreDeplacements, board);
    /*
    float score = calculer_score(board, couleur);
    printf("score : %f\n", score);
    printf("nb deplacemnt : %i\n", nombreDeplacements);
    afficheDeplacements(deplacements, nombreDeplacements);
    */
    if (nombreDeplacements == 0) {
        return (struct Deplacement) { -5,-5,-5,-5 };
    }


    time_t Start;
    

    Start = time(NULL);

    float score_rep = -9999;
    int rep = 0;

    // Tableau de threads
    pthread_t threads[nombreDeplacements];
    struct ThreadArgs threadArgs[nombreDeplacements];

    // Créer un thread pour chaque déplacement possible
    for (int i = 0; i < nombreDeplacements; i++) {
        threadArgs[i].tours_restant = tours_restant - 1;
        threadArgs[i].couleur = inverse(couleur);
        threadArgs[i].IA_Couleur = couleur;
        copy_board(board, threadArgs[i].board);
        movePiece(deplacements[i], threadArgs[i].board, couleur);
        pthread_create(&threads[i], NULL, threadFunc, (void*)&threadArgs[i]);
    }




    int duration;// Durée en secondes
    if(tours_restant<2)
    {
        duration = 2;
    }
    else
    {
        duration = tours_restant; 
    }
    

    /*
    time_t End;
    

    End = time(NULL);
    int a = 0;
    while(End - Start < duration);
    {
        End = time(NULL);
        for (size_t i = 0; i < 1000; i++)
        {
            a++;
        }
        for (size_t i = 0; i < 1000; i++)
        {
            a--;
        }

    }
    */
    sleep(duration);
    // Attendre la fin de chaque thread et récupérer les résultats
    /*
    for (int i = 0; i < nombreDeplacements; i++) {
        //pthread_join(threads[i], NULL);

        // Récupérer le résultat à l'aide du pointeur
        float s = threadArgs[i].result;
        if (s > score_rep) {
            score_rep = s;
            rep = i;
        }
        sleep(duration);
        current = time(NULL);
        if (current - Start >= duration) {
            // Si la durée écoulée dépasse la durée souhaitée, mettre fin aux threads restants
            break;
        }

    }
    */
    for (int i = 0; i < nombreDeplacements; i++) {
        float s = threadArgs[i].result;
        if (s > score_rep) {
            score_rep = s;
            rep = i;
        }
    }
    // Terminer les threads restants
    for (int i = 0; i < nombreDeplacements; i++) {
        if (!pthread_equal(threads[i], pthread_self())) {
            pthread_cancel(threads[i]);
        }
    }

  

    //time_t Start;
    time_t End;
    Start = time(NULL);    
    // Attendre la fin de chaque thread et récupérer les résultats
    for (int i = 0; i < nombreDeplacements; i++) {
        pthread_join(threads[i], NULL);
    }
    End = time(NULL);   
    //printf("Le temps por que sa s'arrète actuel est de : %ld\n", End - Start);
    /* test */
    //printf("déplavement efectuer %i %i %i %i",deplacements[rep].xArrivee,deplacements[rep].yArrivee,deplacements[rep].xDepart,deplacements[rep].yDepart);
    movePiece(deplacements[rep], board, couleur);
    return deplacements[rep];
}






/*

void* threadFunc2(void* args) {
    struct ThreadArgs2* threadArgs = (struct ThreadArgs2*)args;
    threadArgs->result = main_minmax2(threadArgs->tours_restant, threadArgs->couleur, threadArgs->board);
    return NULL;
}

struct Deplacement main_minmax(int tours_restant, int couleur, struct Piece board[8][8]) {
    struct ThreadArgs2 threadArgs;
    threadArgs.tours_restant = tours_restant;
    threadArgs.couleur = couleur;
    copy_board(board, threadArgs.board);

    pthread_t thread;
    pthread_create(&thread, NULL, threadFunc2, (void*)&threadArgs);

    // Attendre la fin du thread et récupérer le résultat
    pthread_join(thread, NULL);
    struct Deplacement rep =  threadArgs.result;


    

}
*/


struct Deplacement main_minmax_ancien(int tours_restant, int couleur, struct Piece board[8][8])
{

    struct Deplacement deplacements[100];
    int nombreDeplacements=0;
    deplacementsPossibles(couleur, deplacements, &nombreDeplacements, board);


    float score = calculer_score(board, couleur);

    //printf("score : %f\n",score);


    //printf("nb deplacemnt : %i\n",nombreDeplacements);

    //afficheDeplacements(deplacements, nombreDeplacements);

    if (nombreDeplacements == 0)
    {
        return (struct Deplacement){-5,-5,-5,-5};
    }


    
    float score_rep = -9999;  // score initialisé à une valeur très basse
    int rep = 0;              // index du déplacement sélectionné
    
    for (int i = 0; i < nombreDeplacements; i++)
    {
        struct Piece board2[8][8];
        copy_board(board, board2);
        //affichePlateau(board2);
        movePiece(deplacements[i], board2, couleur);
        //affichePlateau(board2);
        float s = minmax_ancien(tours_restant-1, inverse(couleur),couleur, board2);

        if (s > score_rep)
        {
            score_rep = s;
            rep = i;
        }
    }


    movePiece(deplacements[rep], board, couleur);
    return deplacements[rep];
}


struct Deplacement conversionString(char* str, struct Piece board[8][8]) {
    struct Deplacement resultat;
    
    resultat.xDepart = 7-(str[1] - '1');
    resultat.yDepart = str[0] - 'a';
    resultat.xArrivee = 7 -( str[3] - '1');
    resultat.yArrivee = str[2] - 'a';

    if (board[resultat.xDepart][resultat.yDepart].type == ROI)
    {
        if (resultat.xDepart - resultat.xArrivee == 2)
        {
            resultat.xDepart = -3;
        }
        else if (resultat.xDepart - resultat.xArrivee == -2)
        {
            resultat.xDepart = -2;
        }
    }
    
    return resultat;
}





struct Deplacement ouverture_bot(int argc, struct Deplacement argv[], int* nb_deplacements, struct Piece board[8][8]) {
    if (*nb_deplacements == 0)
    {
        return (struct Deplacement) {6,4,4,4};
    }
    
    struct Deplacement fin = {-5,-5,-5,-5};
    FILE* fp = fopen("ouverture.txt", "r");
    if (fp == NULL) {
        perror("Impossible d'ouvrir le fichier ouverture.txt");
        exit(1);
    }
    int k =0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        int i = 0;
        k =0;
        while (line[i] != '\0') {
            // Récupère le prochain mouvement de la ligne
            //i = 0;
            struct Deplacement mouvement = conversionString(&line[i],board);
            // Vérifie si le mouvement correspond à l'élément suivant du tableau argv

            if (    ((mouvement.xDepart == -2 || mouvement.xDepart == -3) && mouvement.xDepart == argv[k].xDepart)
                    || (mouvement.xDepart == argv[k].xDepart
                    && mouvement.yDepart == argv[k].yDepart
                    && mouvement.xArrivee == argv[k].xArrivee
                    && mouvement.yArrivee == argv[k].yArrivee)) {
                // Le mouvement correspond, on passe à l'élément suivant de argv
                (k)++;
                i += 5;
                // Si on a atteint la fin de argv, on retourne NULL
                if (k >= *nb_deplacements) {
                    fclose(fp);
                    struct Deplacement dep = conversionString(&line[i],board);
                    printf("mouvement %i %i %i %i\n",dep.xArrivee,dep.xDepart,dep.yArrivee,dep.yDepart);
                    return dep;
                }
            } else {
                // Le mouvement ne correspond pas, on passe à la ligne suivante
                break;
            }

            // Déplace le curseur à la position du prochain mouvement
            //while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0') {
            //    i++;
            //}
            //i++; // Ignore l'espace qui suit le mouvement
        }
    }

    // On a parcouru tout le fichier sans trouver de correspondance, on retourne NULL
    fclose(fp);
    return fin;
}



int transcription(int x){
    int comp = x;
    int res = 0;
    while(x-TILE_SIZE>0){
        res++;
        x = x - TILE_SIZE;

    }
    return res;
}

void play(SDL_Window *window, int mode, int difficulty_bot, int theme)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());

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


    struct Piece board[8][8];
    // rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1

    int nbDeplacements = 0;
    struct Deplacement deplacements[100];
    int couleur = BLANC;
    struct Deplacement last_deplacements[500];
    int last = 0;
    int is_open = 0;
    
    SDL_Event e;
    display_menu(renderer);
    if(mode != 4){
        initialiserPlateau(board, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
        deplacementsPossibles(couleur,deplacements, &nbDeplacements, board);
        display_whoplay(renderer, couleur);
        draw_board(theme, renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
    }
    else{
        initialiserPlateau(board, "8/8/8/8/8/8/8/8 w - - 0 1");
        draw_board_fourth(renderer);
        play_but(renderer);
        piece_fourth(renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
        
    }
    struct Deplacement move;

    //struct Piece list_dead_piece[100];
    //int nb_dead_piece = 0;
    SDL_RenderPresent(renderer);
    SDL_DestroyRenderer(renderer);

    struct Piece piece;
    move.xDepart = -1;
    move.xArrivee = -1;
    move.yDepart = -1;
    move.yArrivee = -1;
    int x, y;
    while (true){
        if(nbDeplacements == 0 && mode != 4){
            SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL)
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
            nbDeplacements = 1;
            draw_board(theme, renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
            display_end_screen(renderer);
            SDL_RenderPresent(renderer);
            SDL_DestroyRenderer(renderer);
            while (true)
            if (SDL_PollEvent(&e) != 0)
                if (e.type == SDL_QUIT)
                    return 0;
                else if (e.type == SDL_MOUSEBUTTONUP){
                    SDL_GetMouseState(&x, &y);
                    if(x>1120 && x<1370 && y<487 && y>400){
                        play(window, mode, difficulty_bot, theme);
                        return;
                    }
                    else if(x>1120 && x<1370 && y<587 && y>500){
                        fun_main(window, theme);
                        return;
                    }
                }
            }
        else if(mode == 2 && couleur == NOIR){
            SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL)
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
            if(is_open == 0){
                struct Deplacement dep = ouverture_bot(200, last_deplacements, &last, board);
                if(dep.xArrivee == -5)
                    is_open = 1;
                else{
                    movePiece(dep, board, couleur);
                    last_deplacements[last] = dep;
                    last++;
                }
                draw_board(theme, renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                nbDeplacements = 0;
                display_piece_to_play(board[dep.xArrivee][dep.yArrivee].type, board[dep.xArrivee][dep.yArrivee].couleur, renderer, dep.yArrivee,dep.xArrivee,white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                couleur = BLANC;
                display_whoplay(renderer, couleur);
                float s = calculer_score_V2(board, BLANC);
                display_score(renderer, (int)s);
                SDL_RenderPresent(renderer);
                deplacementsPossibles(couleur, deplacements, &nbDeplacements, board);
            }
            if(is_open == 1){
                struct Deplacement dep = main_minmax(difficulty_bot,NOIR,board);
                draw_board(theme, renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                couleur = BLANC;
                nbDeplacements = 0;
                float s = calculer_score_V2(board, BLANC);
                display_piece_to_play(board[dep.xArrivee][dep.yArrivee].type, board[dep.xArrivee][dep.yArrivee].couleur, renderer, dep.yArrivee,dep.xArrivee,white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                display_score(renderer, (int)s);
                display_whoplay(renderer, couleur);
                SDL_RenderPresent(renderer);
                deplacementsPossibles(couleur, deplacements, &nbDeplacements, board);
            }
            SDL_DestroyRenderer(renderer);
        }
        else if(mode == 3){
            SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL)
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
            if(is_open == 0){
                struct Deplacement dep = ouverture_bot(200, last_deplacements, &last, board);
                if(dep.xArrivee == -5)
                    is_open = 1;
                else{
                    movePiece(dep, board, couleur);
                    last_deplacements[last] = dep;
                    last++;
                }
                draw_board(theme, renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                couleur = BLANC;
                display_whoplay(renderer, couleur);
                SDL_RenderPresent(renderer);
                nbDeplacements = 0;
                deplacementsPossibles(couleur, deplacements, &nbDeplacements, board);
            }
            if(is_open == 1){
                if(couleur == NOIR){
                    struct Deplacement rep1 = main_minmax(4,couleur,board);
                    if (rep1.xArrivee == -5){
                        nbDeplacements = 0;
                        continue;
                    }
                }
                else
                {
                    struct Deplacement rep2 = main_minmax(3,couleur,board);
                    if (rep2.xArrivee == -5){
                        nbDeplacements = 0;
                        continue;
                    }
                }
                    
                draw_board(theme, renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                if (couleur == BLANC)
                    couleur = NOIR;
                else
                    couleur = BLANC;
                display_whoplay(renderer, couleur);
                SDL_RenderPresent(renderer);
                nbDeplacements = 0;
                deplacementsPossibles(couleur, deplacements, &nbDeplacements, board);
            }
            SDL_DestroyRenderer(renderer);
        }
        else if (SDL_PollEvent(&e) != 0)
            if (e.type == SDL_MOUSEBUTTONUP){
                SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
                if (renderer == NULL)
                    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
                SDL_GetMouseState(&x, &y);
                if(x>1430 && x<1480 && y<70 && y>20){
                    display_left_game(renderer);
                    SDL_RenderPresent(renderer);
                    while (true)
                        if (SDL_PollEvent(&e) != 0)
                            if (e.type == SDL_QUIT)
                                return 0;
                            else if (e.type == SDL_MOUSEBUTTONUP){
                                SDL_GetMouseState(&x, &y);
                                if(x>500 && x<1000 && y<660 && y>500){
                                    SDL_DestroyRenderer(renderer);
                                    fun_main(window, theme);
                                    return;
                                }
                                else if(x>1050 && x<1150 && y<270 && y>170){
                                    display_menu(renderer);
                                    if(mode != 4)
                                        display_whoplay(renderer, couleur);
                                    else
                                        piece_fourth(renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                                    draw_board(theme, renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                                    SDL_RenderPresent(renderer);
                                    break;
                                }
                            }
                    SDL_DestroyRenderer(renderer);
                }
                else if(mode == 4){
                    if(x>1100 && x<1400 && y>890 && y<960){
                        mode = 2;
                        nbDeplacements = 0;
                        display_menu(renderer);
                        display_whoplay(renderer, BLANC);
                        deplacementsPossibles(BLANC, deplacements, &nbDeplacements, board);
                        SDL_DestroyRenderer(renderer);
                    }
                    else{
                        int piece_to_movex = transcription(x);
                        int piece_to_movey = transcription(y);
                        if(piece_to_movex >=8 && piece_to_movex<=9 && piece_to_movey >=1 && piece_to_movey<=6){
                            move.xDepart = piece_to_movex;
                            if(piece_to_movex == 8)
                                piece.couleur = NOIR;
                            else if (piece_to_movex == 9)
                                piece.couleur = BLANC;
                            if(piece_to_movey == 1)
                                piece.type = PION;
                            else if(piece_to_movey == 2)
                                piece.type = CAVALIER;
                            else if(piece_to_movey == 3)
                                piece.type = FOU;
                            else if(piece_to_movey == 4)
                                piece.type = TOUR;
                            else if(piece_to_movey == 5)
                                piece.type = DAME;
                            else if(piece_to_movey == 6)
                                piece.type = ROI;
                            display_menu(renderer);
                            piece_fourth(renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                            display_piece_to_play(piece.type, piece.couleur, renderer, piece_to_movex,piece_to_movey,white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                            draw_board(theme,renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                            play_but(renderer);
                        }
                        else{
                            if(piece_to_movex >=0 && piece_to_movex<=7 && piece_to_movey >=0 && piece_to_movey<=7){
                                board[piece_to_movey][piece_to_movex] = piece;
                                move.xDepart = -1;
                                display_menu(renderer);
                                piece_fourth(renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                                display_piece_to_play(piece.type, piece.couleur, renderer, piece_to_movex,piece_to_movey,white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                                draw_board(theme,renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                                play_but(renderer);
                            }
                        }
                        SDL_RenderPresent(renderer);
                        SDL_DestroyRenderer(renderer);
                    }
                }
                else{
                    //dead_pieces(result, board, couleur, &i);
                    //display_dead_piece(result, board, renderer, couleur, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface,  black_cavalier_surface, black_rook_surface, black_king_surface, black_queen_surface);
                    int piece_to_movex = transcription(x);
                    int piece_to_movey = transcription(y);
                    if(piece_to_movex > 7){
                        SDL_DestroyRenderer(renderer);
                        continue;
                    }
                    else if(move.xDepart == -1 && board[piece_to_movey][piece_to_movex].type != PAS_DE_PIECE && board[piece_to_movey][piece_to_movex].couleur == couleur){
                        move.xDepart = piece_to_movey;
                        move.yDepart = piece_to_movex;
                        display_piece_to_play(board[piece_to_movey][piece_to_movex].type, couleur, renderer, piece_to_movex,piece_to_movey,white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                        display_move(move.xDepart, move.yDepart, board, deplacements, nbDeplacements, renderer);
                        SDL_RenderPresent(renderer);
                    }
                    else{
                        move.xArrivee = piece_to_movey;
                        move.yArrivee = piece_to_movex;
                        if(board[piece_to_movey][piece_to_movex].couleur == couleur){
                            move.xDepart = piece_to_movey;
                            move.yDepart = piece_to_movex;
                            draw_board(theme,renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                            display_piece_to_play(board[piece_to_movey][piece_to_movex].type, couleur, renderer, piece_to_movex,piece_to_movey,white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                            display_move(move.xDepart, move.yDepart, board, deplacements, nbDeplacements, renderer);
                            SDL_RenderPresent(renderer);
                        }
                        else if((board[move.xDepart][move.yDepart].type == ROI) && ((piece_to_movey == 7 && piece_to_movex == 6) || (piece_to_movey == 7 && piece_to_movex == 2) || (piece_to_movey == 0 && piece_to_movex == 6) || (piece_to_movey == 0 && piece_to_movex == 2))){
                            if(piece_to_movex == 2)
                                move.xDepart = -3;
                            else
                                move.xDepart = -2;
                            if(estPresent(move, deplacements, nbDeplacements)){
                                movePiece(move, board, couleur);
                                draw_board(theme,renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                                display_piece_to_play(board[piece_to_movey][piece_to_movex].type, couleur, renderer, piece_to_movex,piece_to_movey,white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                                SDL_RenderPresent(renderer);
                                move.xDepart = -1;
                                move.yDepart = -1;
                                if (couleur == NOIR)
                                    couleur = BLANC;
                                else
                                    couleur = NOIR;
                                nbDeplacements = 0;
                                deplacementsPossibles(couleur, deplacements, &nbDeplacements, board);
                            }
                            else{
                                draw_board(theme,renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                                SDL_RenderPresent(renderer);
                                move.xDepart = -1;
                                move.yDepart = -1;
                            }
                        }
                        else if(!estPresent(move, deplacements, nbDeplacements)){
                            draw_board(theme,renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                            SDL_RenderPresent(renderer);
                            move.xDepart = -1;
                            move.yDepart = -1;
                        }
                        else{
                            last_deplacements[last] = move;
                            last++;
                            movePiece(move, board, couleur);
                            draw_board(theme,renderer, board, white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                            display_piece_to_play(board[piece_to_movey][piece_to_movex].type, couleur, renderer, piece_to_movex,piece_to_movey,white_pion_surface, white_cavalier_surface, white_fou_surface, white_rook_surface, white_king_surface, white_queen_surface, black_pion_surface, black_fou_surface, black_cavalier_surface,black_rook_surface,black_king_surface, black_queen_surface);
                            if (couleur == NOIR)
                                couleur = BLANC;
                            else
                                couleur = NOIR;
                            display_whoplay(renderer, couleur);
                            move.xDepart = -1;
                            move.yDepart = -1;
                            float s = calculer_score_V2(board, BLANC);
                            display_score(renderer, (int)s);
                            SDL_RenderPresent(renderer);
                            nbDeplacements = 0;
                            deplacementsPossibles(couleur, deplacements, &nbDeplacements, board);
                        }
                    }
                    SDL_DestroyRenderer(renderer);
                }
        
            }
            else if(e.type == SDL_QUIT)
                return;
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void fun_main(SDL_Window* window, int theme){
    SDL_Renderer* renderer= SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    display_first_screen(renderer);
    SDL_RenderPresent(renderer);
    int x, y;
    SDL_Event e;
    while (true)
        if (SDL_PollEvent(&e) != 0)
            if (e.type == SDL_QUIT)
                return 0;
            else if (e.type == SDL_MOUSEBUTTONUP){
                SDL_GetMouseState(&x, &y);
                if(x<1050 && x>450 && y<937 && y>750){
                    SDL_DestroyRenderer(renderer);
                    play(window, 1, 0, theme);
                    break;
                }
                else if(x<1050 && x>450 && y<737 && y>550){
                    display_choose_difficulty(renderer);
                    SDL_RenderPresent(renderer);
                    SDL_DestroyRenderer(renderer);
                    while (true)
                        if (SDL_PollEvent(&e) != 0)
                            if (e.type == SDL_QUIT)
                                return 0;
                            else if (e.type == SDL_MOUSEBUTTONUP){
                                SDL_GetMouseState(&x, &y);
                                if(x>500 && x<1000 && y<510 && y>350)
                                    play(window, 2, 2, theme);
                                else if(x>500 && x<1000 && y<710 && y>550)
                                    play(window, 2, 3, theme);
                                else if(x>500 && x<1000 && y<910 && y>750)
                                    play(window, 2, 4, theme);
                                else if(x>1050 && x<1150 && y<120 && y>20){
                                    fun_main(window, theme);
                                    break;
                                }
                            }   
                    break;
                }
                else if(x<1050 && x>450 && y<537 && y>350){
                    SDL_DestroyRenderer(renderer);
                    play(window, 3, 0, theme);
                    break;
                }
                else if(x<400 && x>200 && y<950 && y>750){
                    SDL_DestroyRenderer(renderer);
                    play(window, 4, 0, theme);
                    break;
                }
                else if(x>1430 && x<1480 && y<70 && y>20){
                    display_theme(renderer);
                    SDL_RenderPresent(renderer);
                    while (true)
                        if (SDL_PollEvent(&e) != 0)
                            if (e.type == SDL_QUIT)
                                return 0;
                            else if (e.type == SDL_MOUSEBUTTONUP){
                                SDL_GetMouseState(&x, &y);
                                if(x>500 && x<1000 && y<660 && y>500){
                                    SDL_DestroyRenderer(renderer);
                                    fun_main(window, theme);
                                    return;
                                }
                                if(x>500 && x<740 && y<800 && y>700){
                                    SDL_DestroyRenderer(renderer);
                                    fun_main(window, 0);
                                    return;
                                }
                                if(x>760 && x<1000 && y<800 && y>700){
                                    SDL_DestroyRenderer(renderer);
                                    fun_main(window, 1);
                                    return;
                                }
                            }
                    SDL_DestroyRenderer(renderer);
                }
            }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void test()
{
    struct Piece board[8][8];
    
    time_t Start;
    time_t End;
    
    initialiserPlateau(board, "rn1qkbnr/pbpppppp/1p6/P7/8/1B6/1PPPPPPP/RNBQK1NR b Qkq - 0 1");
    Start = time(NULL);

    //printf("Le temps actuel est : %ld\n", currentTime);


    struct Deplacement a;
    a = main_minmax(2,NOIR,board);
    printf("déplavement efectuer %i %i %i %i\n",a.xDepart,a.yDepart,a.xArrivee,a.yArrivee);
    End = time(NULL);
    printf("Le temps actuel est : %ld\n", End - Start);
    initialiserPlateau(board, "rn1qkbnr/pbpppppp/1p6/P7/8/1B6/1PPPPPPP/RNBQK1NR b Qkq - 0 1");
    Start = time(NULL);
    a = main_minmax(5,NOIR,board);
    printf("déplavement efectuer %i %i %i %i",a.xDepart,a.yDepart,a.xArrivee,a.yArrivee);
    End = time(NULL);
    printf("Le temps actuel est : %ld\n", End - Start);
    initialiserPlateau(board, "rn1qkbnr/pbpppppp/1p6/P7/8/1B6/1PPPPPPP/RNBQK1NR b Qkq - 0 1");
    Start = time(NULL);
    a = main_minmax(10,NOIR,board);
    printf("déplavement efectuer %i %i %i %i",a.xDepart,a.yDepart,a.xArrivee,a.yArrivee);
    End = time(NULL);
    printf("Le temps actuel est : %ld\n", End - Start);
}


void test2()
{
    struct Piece board[8][8];
    struct Piece board2[8][8];
    initialiserPlateau(board, "rn1qkbnr/pbpppppp/1p6/P7/8/1B6/1PPPPPPP/RNBQK1NR b Qkq - 0 1");
    time_t Start;
    time_t End;
    Start = time(NULL);
    for (size_t i = 0; i < 10000000; i++)
    {
        copy_board(board,board2);
    }
    End = time(NULL);
    printf("Le temps actuel est : %ld\n", End - Start);
}

void test3()
{
    struct Piece board[8][8];
    struct Piece board2[8][8];
    int nbDeplacements = 0;

    initialiserPlateau(board, "rn1qkbnr/pbpppppp/1p6/P7/8/1B6/1PPPPPPP/RNBQK1NR b Qkq - 0 1");
    time_t Start;
    time_t End;
    struct Deplacement deplacements[100];
    Start = time(NULL);
    
    for (size_t i = 0; i < 10000000; i++)
    {
        deplacementsPossibles(NOIR, deplacements, &nbDeplacements, board);
        nbDeplacements = 0;
    }
    End = time(NULL);
    printf("Le temps actuel est : %ld\n", End - Start);
}


void test4()
{
    struct Piece board[8][8];
    struct Piece board2[8][8];
    int nbDeplacements = 0;

    initialiserPlateau(board, "rn1qkbnr/pbpppppp/1p6/P7/8/1B6/1PPPPPPP/RNBQK1NR b Qkq - 0 1");
    time_t Start;
    time_t End;
    struct Deplacement deplacements[100];
    Start = time(NULL);
    
    for (size_t i = 0; i < 10000000; i++)
    {
        calculer_score(board,NOIR);
    }
    End = time(NULL);
    printf("Le temps actuel est : %ld\n", End - Start);
}


void test_IA_Fen(char fen[],struct Deplacement rep,int temps)
{
    struct Piece board[8][8];
    initialiserPlateau(board, fen);
    struct Deplacement a;
    a = main_minmax(temps,NOIR,board);

    if (a.xArrivee == rep.xArrivee && a.yArrivee == rep.yArrivee && a.xDepart == rep.xDepart && a.yDepart == rep.yDepart)
    {
        couleur("1;32"); // Texte en vert
        
        printf("correct\n");
    }
    else
    {
        couleur("1;31"); // Texte en rouge
        printf("erreur\n");
    }
    couleur("0");

}

void test_IA_Fen2(char fen[],struct Deplacement rep[],struct Deplacement depl[],int temps,int nbrep)
{
    struct Piece board[8][8];
    initialiserPlateau(board, fen);
    for (size_t i = 0; i < nbrep; i++)
    {
        struct Deplacement a;
        a = main_minmax(temps,NOIR,board);
        struct Deplacement La[100] ;
        La[i]= a;

        if (a.xArrivee == rep[i].xArrivee && a.yArrivee == rep[i].yArrivee && a.xDepart == rep[i].xDepart && a.yDepart == rep[i].yDepart)
        {
            movePiece(a,board,NOIR);
            if (i+1 < nbrep)
            {
               movePiece(depl[i],board,BLANC);
            }
            
            
        }
        else
        {
            afficheDeplacements(La,i+1);
            //printf("\n");
            couleur("1;31"); // Texte en rouge
            printf("erreur\n");
            couleur("0");
            return;
        }
        
    }
    
    couleur("1;32"); // Texte en vert
            
    printf("correct\n");
    couleur("0");

}



struct Deplacement ini(int x1,int y1,int x2,int y2)
{
    struct Deplacement rep;
    rep.xDepart = x1;
    rep.yDepart = y1;
    rep.xArrivee = x2;
    rep.yArrivee = y2;
    return rep;
}

void test_IA(int temps)
{
    printf("Temps: %i\n", temps);

    char fen[100];
    printf("Mat en 1\n");
    char fen1[100] = "rnb1kbnr/pppp1ppp/2q5/8/8/8/PPPPKPPP/RNBQ1BNR b kq - 0 1";
    struct Deplacement D1 = {2,2,4,4};
    struct Deplacement L1[100];
    struct Deplacement L2[100];
    L1[0] = D1;
    test_IA_Fen2(fen1,L1,L2,temps,1);

    printf("Mat en 2\n");


    L1[0] =ini(1,6,1,7); 
    L1[1] =ini(2,4,3,5); 

    L2[0] =ini(3,7,2,6); 
    test_IA_Fen2("8/p5r1/4b3/4k1PK/PR2p3/4P3/5PB1/8 b - - 0 2",L1,L2,temps,2);


    printf("Mat en 3\n");
    L1[0] =ini(2,4,4,7); 
    L1[1] =ini(2,1,6,5); 
    L1[2] =ini(2,3,3,5);

    L2[0] =ini(7,4,6,4); 
    L2[1] =ini(6,4,5,3); 
    test_IA_Fen2("3k3r/3nbppp/pq1pp1b1/4P3/4B1P1/1PN2P1P/P1PB4/R2QK2R b - - 2 1",L1,L2,temps,3);


    printf("Ouverture\n");
    
    // trés facile
    char fen2[100] = "r2qk2r/1p3pbp/p3bnp1/2pp4/P1BN4/1PN5/1BPP1PPP/R2QR1K1 b - - 0 1";

    L1[0] =ini(3,2,4,3);
    L1[1] =ini(3,3,4,2);
    L2[0] =ini(5,2,6,4);
    test_IA_Fen2(fen2,L1,L2,temps,2);


    //Normale
    char fen4[100] = "r2q1rk1/p1p1ppbp/1p3Bp1/8/8/1P1P4/P1PNBPbP/R2Q1RK1 b - - 0 1";
    
    L1[0] =ini(6,6,7,5);
    L1[1] =ini(7,5,6,4);
    L2[0] =ini(2,5,1,6);
    test_IA_Fen2(fen4,L1,L2,temps,2);

    printf("Finale\n");

    // Normal
    char fen3[100] = "8/p4k1K/1p4p1/5p2/8/2P3P1/PP5P/8 b - - 0 1";

    L1[0] =ini(2,6,3,6);
    L1[1] =ini(3,5,4,5);
    L1[2] =ini(4,5,5,5);
    L2[0] =ini(1,7,2,7);
    L2[1] =ini(4,5,5,5);
    test_IA_Fen2(fen3,L1,L2,temps,3);

    printf("Milieu de jeux\n");

    // trés Facile
    L1[0] =ini(2,4,3,2); 
    L1[1] =ini(0,2,3,2); 
    L2[0] =ini(1,0,3,2); 
    test_IA_Fen2("1qr3k1/Qb1pbppp/4pn2/1N6/2n1P3/P1N2P2/1P2B1PP/R4RK1 b - - 0 1",L1,L2,temps,2);

    // Facile
    L1[0] =ini(3,3,3,2); 
    L1[1] =ini(3,2,3,6); 
    L1[2] =ini(3,6,5,4); 
    L2[0] =ini(5,5,4,3); 
    L2[1] =ini(4,3,2,4); 
    test_IA_Fen2("5rk1/2p3pp/1p1p1n2/1P1q2B1/4p3/2P2N1P/6P1/1Q1R2K1 b - - 0 2",L1,L2,temps,3);


    // Normal
    L1[0] =ini(2,1,3,0); 
    L1[1] =ini(2,5,4,4); 
    L1[2] =ini(3,0,6,3); 
    L2[0] =ini(7,0,5,0); 
    L2[1] =ini(5,2,4,4); 
    test_IA_Fen2("r1b2rk1/1pqp1ppp/1b2pn2/1B6/P3P3/2N1B3/2PQ1PPP/R4RK1 b - - 0 2",L1,L2,temps,3);

    // Difficile
    L1[0] =ini(6,6,5,6); 
    L1[1] =ini(2,7,7,7); 
    L1[2] =ini(7,7,7,5);
    L1[3] = ini(4,6,5,7);

    L2[0] =ini(7,5,6,5); 
    L2[1] =ini(4,2,7,5); 
    L1[2] = ini(7,4,7,5);
    test_IA_Fen2("4rk2/1p5r/p7/2R2PQ1/1PB1P1b1/6P1/3N2q1/4KR2 b - - 0 2",L1,L2,temps,4);

}




void test10()
{


    struct Piece board[8][8];
    
    time_t Start;
    time_t End;
    
    initialiserPlateau(board, "rn1qkbnr/pbpppppp/1p6/P7/8/1B6/1PPPPPPP/RNBQK1NR b - - 0 1");
    struct Deplacement a;
    Start = time(NULL);

    //printf("Le temps actuel est : %ld\n", currentTime);


    minmax_ancien(5,NOIR,BLANC, board);
    //printf("déplavement efectuer %i %i %i %i\n",a.xDepart,a.yDepart,a.xArrivee,a.yArrivee);
    End = time(NULL);
    printf("Le temps actuel est : %ld\n", End - Start);
    initialiserPlateau(board, "rn1qkbnr/pbpppppp/1p6/P7/8/1B6/1PPPPPPP/RNBQK1NR b - - 0 1");
    Start = time(NULL);
    minmax2(5,NOIR,BLANC, board);
    //printf("déplavement efectuer %i %i %i %i",a.xDepart,a.yDepart,a.xArrivee,a.yArrivee);
    End = time(NULL);
    printf("Le temps actuel est : %ld\n", End - Start);

}

int main() {
    //test4();
    //return 0;

    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow("Chess SUV", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1500, 980, SDL_WINDOW_SHOWN);
    if (window == NULL)
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

    fun_main(window, 0);
    
    return 0;
}