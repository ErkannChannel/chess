#include <stdio.h>
#include "src/gui.c"


const int BLANC = 1;
const int NOIR = 0;
const int VIDE = -1;

#define couleur(param) printf("\033[%sm",param)


void affichePlateau(struct Piece plateau[8][8]) {
    // Affiche les lettres de colonne en haut de l'échiquier
    printf("   A B C D E F G H\n");
    // Boucle pour parcourir toutes les lignes de l'échiquier
    for(int i = 0; i < 8; i++) {
        // Affiche le numéro de la ligne avant de parcourir les colonnes
        printf(" %d ", 8-i);
        // Boucle pour parcourir toutes les colonnes de l'échiquier
        for(int j = 0; j < 8; j++) {
            // Si la case actuelle contient une pièce
            if(plateau[i][j].name != ' ') {
                // Si la pièce est blanche, affiche son nom en majuscule
                if (plateau[i][j].couleur == 0) {
                    couleur("36");
                    printf("%c ", tolower(plateau[i][j].name));
                    couleur("0");
                } else {
                    // Sinon, affiche son nom en minuscule pour indiquer qu'il s'agit d'une pièce noire
                    couleur("31");
                    printf("%c ", plateau[i][j].name);
                    couleur("0");
                }
            } else {
                // Si la case actuelle est vide, affiche un point
                printf(". ");
            }
        }
        // Affiche le numéro de la ligne après avoir parcouru les colonnes
        printf(" %d\n", 8-i);
    }
    // Affiche les lettres de colonne en bas de l'échiquier
    printf("   A B C D E F G H\n");
}


int RoiEnEchec_player(int xRoi,int yRoi, int couleur,struct Piece board[8][8])
{



 int j;
 int i;


    if (couleur == BLANC)
    {
        i = xRoi-1;
        j = yRoi-1;
        if (i >= 0 && j >= 0 && board[i][j].type == PION && board[i][j].couleur != couleur)
        {
            return 1;
        }
        i = xRoi-1;
        j = yRoi+1;
        if (i >= 0 && j < 8 && board[i][j].type == PION && board[i][j].couleur != couleur)
        {
            return 1;
        } 
    }
    else
    {
        i = xRoi+1;
        j = yRoi-1;
        if (i < 8 && j >= 0 && board[i][j].type == PION && board[i][j].couleur != couleur)
        {
            return 1;
        }
        i = xRoi+1;
        j = yRoi+1;
        if (i < 8 && j < 8 && board[i][j].type == PION && board[i][j].couleur != couleur)
        {
            return 1;
        }
    }



if (xRoi - 2 >= 0) {
        if (yRoi - 1 >= 0) {
            if (board[xRoi - 2][yRoi - 1].type == CAVALIER && board[xRoi - 2][yRoi - 1].couleur != couleur ) {

            return 1;
            
            }
        }
        if (yRoi + 1 < 8) {
            if (board[xRoi - 2][yRoi + 1].type == CAVALIER && board[xRoi - 2][yRoi + 1].couleur != couleur) {
            return 1;
            
            
            }
        }
    }

    
    if (xRoi + 2 < 8) {
        if (yRoi - 1 >= 0) {
            if (board[xRoi + 2][yRoi - 1].type == CAVALIER && board[xRoi + 2][yRoi - 1].couleur != couleur) {
            return 1;
            }
        }
        if (yRoi + 1 < 8) {
            if (board[xRoi + 2][yRoi + 1].type == CAVALIER && board[xRoi + 2][yRoi + 1].couleur != couleur) {
            return 1;
            }
        }
    }
    if (yRoi - 2 >= 0) {
        if (xRoi - 1 >= 0) {
            if (board[xRoi - 1][yRoi - 2].type == CAVALIER && board[xRoi - 1][yRoi - 2].couleur != couleur) {
            return 1;
            }
        }
        if (xRoi + 1 < 8) {
            if (board[xRoi + 1][yRoi - 2].type == CAVALIER && board[xRoi + 1][yRoi - 2].couleur != couleur) {
            return 1;
            }
        }
    }
    if (yRoi + 2 < 8) {
        if (xRoi - 1 >= 0) {
            if (board[xRoi - 1][yRoi + 2].type == CAVALIER && board[xRoi - 1][yRoi + 2].couleur != couleur) {
            return 1;
            }
        }
        if (xRoi + 1 < 8) {
            if (board[xRoi + 1][yRoi + 2].type == CAVALIER && board[xRoi + 1][yRoi + 2].couleur != couleur) {
            return 1;
        }
        }
    }







    i = xRoi+1;
    j = yRoi+1;




    while(i < 8 && j < 8 && (board[i][j].type == PAS_DE_PIECE || (board[i][j].type == ROI && board[i][j].couleur == couleur)))
    {
        i++;
        j++;
    }
    if (i < 8 && j < 8 && (board[i][j].type == DAME || board[i][j].type == FOU) && board[i][j].couleur != couleur )
    {
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
        return 1;
    }
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
                return 3;
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
                return 3;
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
                return 4;
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
                return 4;
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
        if ( (cloue == 0 || cloue == 4) && case_existe(x-1,y+1) && board[x-1][y+1].couleur == 0 ) {
            //printf("test 5 : %d \n",board[x-1][y+1].type );
            ajout_deplacement(x, y ,x-1 , y+1,deplacements,nombreDeplacements );    
        }
        if ( (cloue == 0 || cloue == 3 )&&  case_existe(x-1,y-1) && board[x-1][y-1].couleur == 0 ) {
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
        if ( (cloue == 0 || cloue == 3) && case_existe(x+1,y+1) && board[x+1][y+1].couleur == 1 ) {
            //printf("test 7 : %d \n",board[x+1][y+1].type );
            ajout_deplacement(x, y ,x+1 , y+1,deplacements,nombreDeplacements );    
        }
        if ( (cloue == 0 || cloue == 4) && case_existe(x+1,y-1) && board[x+1][y-1].couleur == 1 ) {
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
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (case_existe(x + i, y + j) && (i != 0 || j != 0)) {
                if (board[x + i][y + j].couleur != board[x][y].couleur &&  0 == RoiEnEchec_player(x+i,y+j,board[x][y].couleur,board)) {
                    ajout_deplacement(x, y ,x+i , y+j,deplacements,nombreDeplacements );
                }
            }
        }
    }
    
    // Vérification pour le roque
    if (board[x][y].test_roquable==1 &&((board[x][y].couleur == BLANC && x == 7 && y == 5) ||(board[x][y].couleur == NOIR && x == 0 && y == 5))) {
        if (board[x][y+3].test_roquable==1 && board[x][y+1].type == PAS_DE_PIECE && board[x][y+2].type == PAS_DE_PIECE) {
            printf("petit roque possible\n");
            ajout_deplacement(-2, y ,x , y+3,deplacements,nombreDeplacements );
        }
        if (board[x][y-4].test_roquable==1 && board[x][y-1].type == PAS_DE_PIECE && board[x][y-2].type == PAS_DE_PIECE && board[x][y-3].type == PAS_DE_PIECE) {
            printf("grand roque possible\n");
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
    {
        for (int y = 0 ; y<8 ; y++ )
        {
            if (board[x][y].type == ROI && board[x][y].couleur == couleur)
            {
                // //printf("test 3 : %i \n", x);
                // //printf("test 4 : %i \n", y);
                return x*10+y;
            }
        }
    }
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
       
        if (couleur == NOIR)
        {
            i = x-1;
            j = y-1;
            //printf("test4  \n" );
            if (i >= 0 && j >= 0 && board[i][j].type == PION)
            {
                __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
            i = x-1;
            j = y+1;
            if (i >= 0 && j < 8 && board[i][j].type == PION)
            {
                __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            } 
        }
        else
        {
            //printf("test8 \n");
            i = x+1;
            j = y-1;
            if (i < 8 && j >= 0 && board[i][j].type == PION)
            {
                //printf("test10 \n");
                __interception(i, j,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
                //printf("test10 \n");
            }
            i = x+1;
            j = y+1;
            if (i < 8 && j < 8 && board[i][j].type == PION)
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
        if (couleur == NOIR)
        {
            if ( x+1<8  &&  board[x+1][y].type == PION && board[x+1][y].couleur == NOIR)
            {
                __interception(x+1, y,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
            if ( x+2  == 1 &&  board[x+2][y].type == PION && board[x+2][y].couleur == NOIR)
            {
                __interception(x+2, y,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
            
        }
        else
        {
            if ( x-1>= 0 &&  board[x-1][y].type == PION  && board[x-1][y].couleur == BLANC)
            {
                __interception(x-1, y,x, y, xRoi, yRoi,deplacements, nombreDeplacements, board );
            }
            if ( x-2  == 6 &&  board[x-2][y].type == PION && board[x-2][y].couleur == BLANC)
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
    printf("coordonnés roi %d %d \n",xRoi,yRoi);

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



void afficheDeplacements(struct Deplacement* deplacements, int nbDeplacements,struct Piece board[8][8]) {
    for (int i = 0; i < nbDeplacements; i++) {
        if (deplacements[i].xDepart == -2)
        {
            printf("Deplacement petit Roque\n");
        }
        else if (deplacements[i].xDepart == -3)
        {
            printf("Deplacement grand Roque\n");
        }
        else
            printf("Deplacement %d: %c %c%d -> %c%d\n",i+1,board[deplacements[i].xDepart][deplacements[i].yDepart].name, 'a' + deplacements[i].yDepart, 8 - deplacements[i].xDepart, 'a' + deplacements[i].yArrivee, 8 - deplacements[i].xArrivee);
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
                plateau[i][j].test_roquable = 0;
                ////printf("test 66 %c \n", fen[k]);
                j++;
            }
            else
            {
                plateau[i][j].type = (fen[k] == 'P') ? PION : (fen[k] == 'N') ? CAVALIER : (fen[k] == 'B') ? FOU : (fen[k] == 'R') ? TOUR : (fen[k] == 'Q') ? DAME : ROI;
                plateau[i][j].couleur = (fen[k] < 'a') ? 1 : 0;
                plateau[i][j].name = fen[k];
                plateau[i][j].test_roquable = 0;
                ////printf("test 55 %c \n", fen[k]);
                j++;
            }
            
            
            
        }

        k++;
    }
    /*
    int couleur;
    k++;
    if (fen[k] == 'w')
        couleur = BLANC;
    else 
        couleur = NOIR;
    
    k++;
    while(fen[k] != '-' && ' ')
    {
        if(fen[k] == 'K')
        {
            
        }
        if(fen[k] == 'Q')
        if(fen[k] == 'k')
        if(fen[k] == 'q')
    }

    */

}



void deplacementsPossibles(int couleur,struct Deplacement* deplacements, int* nbDeplacements,  struct Piece board[8][8] )
{
    int Roi = trouverRoi(couleur,board);
    int xRoi = Roi/10;
    int yRoi = Roi%10;
    int menace = RoiEnEchec_bot(xRoi,yRoi,board);
    if (menace == -1)
    {
        // le rois n'est pas en échecs
        printf("le roi n'est pas en echecs\n");
        ajouterDeplacementsPossibles(couleur, deplacements, nbDeplacements, board);
    }
    else
    {
        printf("njvdzvnjodenvode\n");
        if (menace != -2)
        {
            printf("il y a une menace\n");
            interception_global(menace/10,menace%10,xRoi,yRoi,deplacements, nbDeplacements,board,couleur );
        }
        else
        {
            printf("il y a plusieur menace\n");
        }
        ajouterDeplacementRoi(xRoi,yRoi,deplacements,nbDeplacements,board);
    }
    
}


struct Deplacement conversionString(char* str) {
    struct Deplacement resultat;
    if (str[0] == '-')
    {
        printf("roque\n  %d", -(str[1] - '0'));

        resultat.xDepart = -(str[1] - '0');
        return resultat;
    }
    
    //printf("test0 : %c %c %c %c  \n", str[0], str[1], str[2], str[3]);
    resultat.xDepart = 7-(str[1] - '1');
    resultat.yDepart = str[0] - 'a';
    resultat.xArrivee = 7 -( str[3] - '1');
    resultat.yArrivee = str[2] - 'a';
    printf("\n%i  %i move apres trans %i  %i\n", resultat.xDepart, resultat.yDepart, resultat.xArrivee, resultat.yArrivee );
    return resultat;
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
}


void movePiece(struct Deplacement deplacement, struct Piece board[8][8], int couleur)
{
    if (deplacement.xDepart == -2)
    {
        if (couleur == BLANC)
        {
            board[7][6] = board[7][4];
            board[7][5] = board[7][7];
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

}

void test_déplacement()
{
    struct Piece board[8][8];
    initialiserPlateau(board, "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1");
    affichePlateau(board);
    int nombreDeplacements = 0;
    struct Deplacement deplacements[100];
    deplacementsPossibles(BLANC,deplacements,&nombreDeplacements,board);
    printf("test1 : %d \n", nombreDeplacements);
    printf("test2 : %d   %d \n",deplacements[0].xDepart , deplacements[0].yDepart);

    afficheDeplacements(deplacements,nombreDeplacements,board);
}

void test_interception()
{
    struct Piece board[8][8];
    initialiserPlateau(board, "r1b4r/pppppppp/nk2q2R/3p4/8/8/1P3BPP/2b2K1n w - - 0 1");
    affichePlateau(board);
    int nombreDeplacements = 0;
    struct Deplacement deplacements[100];
    interception_global(6,5,2, 1,deplacements, &nombreDeplacements, board,1);
    
    printf("test1 : %d \n", nombreDeplacements);
    printf("test2 : %d   %d \n",deplacements[0].xDepart , deplacements[0].yDepart);
    afficheDeplacements(deplacements,nombreDeplacements,board);
}

int transcription(int x){
    int comp = x;
    int res = 0;
    while(x-64>0){
        res++;
        x = x - 64;
    }
    return res;
}

void play()
{
    struct Piece board[8][8];
    initialiserPlateau(board, "2kbR3/ppp3p1/5pb1/8/1PPb3r/3P4/P4PPP/6K1  ");
    affichePlateau(board);
    int nbDeplacements = 0;
    struct Deplacement deplacements[100];
    int couleur = BLANC;
    deplacementsPossibles(couleur,deplacements, &nbDeplacements, board);

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow("Chess SUV", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 512, 512, SDL_WINDOW_SHOWN);
    if (window == NULL)
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    
    bool quit = false;
    SDL_Event e;
    draw_board(renderer, board);
    SDL_RenderPresent(renderer);
    struct Deplacement move;
    move.xDepart = -1;
    move.xArrivee = -1;
    move.yDepart = -1;
    move.yArrivee = -1;
    int x, y;
    while (true)
        if (SDL_PollEvent(&e) != 0)
            if (e.type == SDL_QUIT)
                return NULL;
            else if (e.type == SDL_MOUSEBUTTONUP){
                SDL_GetMouseState(&x, &y);
                draw_board(renderer, board);
                SDL_RenderPresent(renderer);
                int piece_to_movex = transcription(x);
                int piece_to_movey = transcription(y);
                if(move.xDepart == -1){
                    move.xDepart = piece_to_movey;
                    move.yDepart = piece_to_movex;
                    //display_piece_to_play(board[x][y].type, renderer, piece_to_movex, piece_to_movey);
                    }
                else{
                    move.xArrivee = piece_to_movey;
                    move.yArrivee = piece_to_movex;
                    if(!estPresent(move, deplacements, nbDeplacements)){
                        move.xDepart = -1;
                        move.yDepart = -1;
                        continue;
                    }
                    movePiece(move, board, couleur);
                    affichePlateau(board);
                    draw_board(renderer, board);
                    SDL_RenderPresent(renderer);
                    move.xDepart = -1;
                    move.yDepart = -1;
                    if (couleur == BLANC)
                        couleur = NOIR;
                    else
                        couleur = BLANC;
                    nbDeplacements = 0;
                    deplacementsPossibles(couleur, deplacements, nbDeplacements, board);
                }
            }
                    
    afficheDeplacements(deplacements, nbDeplacements, board);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}





int main() {
    /*
    struct Piece board[8][8];

    //initialiserPlateau(board, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");


    initialiserPlateau(board, "3qk3/1r6/8/n7/1N6/1K6/3n4/8 w - - 0 1");

    //char fen[50] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    //char fen[50] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    //char *ptr = fen;
   
    affichePlateau(board);
    // for (int i = 0; i < 2000000000; i++)
    // {
        //int nombreDeplacements = 0;
        //struct Deplacement deplacements[100];
        //ajouterDeplacementPion(1, 0, deplacements, &nombreDeplacements,board);
        //ajouterDeplacementPion(1, 1, deplacements, &nombreDeplacements,board);
        //ajouterDeplacementPion(1, 2, deplacements, &nombreDeplacements,board);
        //ajouterDeplacementsPossibles(1, deplacements, &nombreDeplacements, board);
    //}
    int val = trouverRoi(1,board);
    printf("cordonnée roi %d %d\n",val/10 ,val%10);
    printf("%d\n", RoiEnEchec_bot(val/10,val%10,board));
    printf("%d\n", RoiEnEchec_player(val/10,val%10,BLANC,board));
    printf("%d\n", RoiEnEchec_player(0,0,BLANC,board));
    printf("%d\n", RoiEnEchec_player(0,4,BLANC,board));
    printf("%d\n", RoiEnEchec_player(0,6,BLANC,board));
    printf("%d\n", RoiEnEchec_player(2,0,BLANC,board));
    for (int i = 0; i < 200000000; i++)
    {
        RoiEnEchec_bot(val/10,val%10,board);
    }
    // int nombreDeplacements = 0;
    // struct Deplacement deplacements[100];
    
    // ajouterDeplacementsPossibles(1, deplacements, &nombreDeplacements, board);


    // afficheDeplacements(deplacements,nombreDeplacements,board);
    
    */
    
    //test_déplacement();
    play();
    return 0;
}
