#include <stdio.h>
#include <stdlib.h>
#define DIMX 4
#define DIMY 4
int main()
{
    int Matrice[DIMX][DIMY];
    int i,j;

    for (j=0; j<DIMY; j++)
    {
        for (i=0; i<DIMX; i++)
        {
            printf("inserire elemento colonna %d e riga %d: ", j, i);
            scanf("%d", &Matrice[j][i]);
        }
    }

    printf("\nLa matrice inserita e':\n");
    for (j=0; j<DIMY; j++)
    {
        for (i=0; i<DIMX; i++)
        {
            printf("%d\t", Matrice[j][i]);
        }
        printf("\n");
    }


    for (j=0; j<DIMY; j++)
    {
        for (i=0; i<DIMX; i++)
        {
            if (i==j) {
                if (Matrice[DIMX-i-1][DIMY+j-1]==0) {
                    printf("la matrice e' triangolare superiore");
                }
            }
        }
    }


    return 0;
}
