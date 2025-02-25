#include <stdio.h>
#include <stdlib.h>
#define DIMX 6
#define DIMY 7

void inserimento (char matrice[][DIMY],char var)
{
    int righe=5,colonna=0,k=1;

    printf("\nInserire le cordinate di dove si vuole inserire la %c, inserire la colonna.", var);
    printf("Colonna: ");
    scanf("%d",&colonna);

    do
    {
        if(matrice[righe][colonna-1]==' ')
        {
            matrice[righe][colonna-1]=var;
            k=0;
        }
        else
        {
            righe--;
        }
    }
    while(k==1);
}

int main()
{
    int i,j;
    char matrice[DIMX][DIMY],var;

    for(i=0; i<DIMX; i++)
    {
        for(j=0; j<DIMY; j++)
        {
            matrice[i][j]= ' ';
        }
    }

    for(i=0; i<DIMX; i++)
    {
        for(j=0; j<DIMY-1; j++)
        {
            printf("  %c  |",matrice[i][j]);
        }
        printf("  %c  ",matrice[i][j]);
        if(i<DIMX-1)
        {
            printf("\n-----+-----+-----+-----+-----+-----+-----\n");
        }
    }

    var='X';
    inserimento(matrice,var);

    for(i=0; i<DIMX; i++)
    {
        for(j=0; j<DIMY-1; j++)
        {
            printf("  %c  |",matrice[i][j]);
        }
        printf("  %c  ",matrice[i][j]);
        if(i<DIMX-1)
        {
            printf("\n-----+-----+-----+-----+-----+-----+-----\n");
        }
    }
    var='O';
    inserimento(matrice,var);

    for(i=0; i<DIMX; i++)
    {
        for(j=0; j<DIMY-1; j++)
        {
            printf("  %c  |",matrice[i][j]);
        }
        printf("  %c  ",matrice[i][j]);
        if(i<DIMX-1)
        {
            printf("\n-----+-----+-----+-----+-----+-----+-----\n");
        }
    }

    return 0;
}
