#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIMX 4
#define DIMY 4
int StampaMatrice (int x[][DIMY]) {

int NumRighe;
int NumColonne;

for (NumRighe = 0; NumRighe < DIMX; NumRighe++)
    {
        for (NumColonne = 0; NumColonne < DIMY; NumColonne++)
        {
            printf("%d\t", x[NumRighe][NumColonne]);
        }
        printf("\n");
    }
return 0;
}

int GeneraMatrice (int x[][DIMY]) {


int NumRighe;
int NumColonne;

    for (NumRighe = 0; NumRighe < DIMX; NumRighe++)
    {
        for (NumColonne = 0; NumColonne < DIMY; NumColonne++)
        {
            x[NumRighe][NumColonne] = (rand() % 10) + 1;
        }
    }

return 0;
}

int TrasponiMatrice (int x[][DIMY], int y[][DIMY]) {

int NumRighe;
int NumColonne;


for (NumRighe = 0; NumRighe < DIMX; NumRighe++)
    {
        for (NumColonne = 0; NumColonne < DIMY; NumColonne++)
        {
            y[NumColonne][NumRighe]=x[NumRighe][NumColonne];
        }
    }

return 0;

}


int main()
{
    int Matrice[DIMX][DIMY];
    int MatriceT[DIMX][DIMY];
    srand(time(NULL));

    GeneraMatrice(Matrice);

    printf("\nLa matrice e':\n");
    StampaMatrice (Matrice);

    TrasponiMatrice(Matrice,MatriceT);

    printf("\nLa matrice dopo la trasposizione e':\n");
    StampaMatrice(MatriceT);

    return 0;
}
