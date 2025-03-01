#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIMX 5
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

int ValoreMassimo (int x[][DIMY]) {

int max=1;
int NumRighe;
int NumColonne;


for (NumRighe = 0; NumRighe < DIMX; NumRighe++)
    {
        for (NumColonne = 0; NumColonne < DIMY; NumColonne++)
        {
            if (x[NumRighe][NumColonne]>max) {
                max = x[NumRighe][NumColonne];
            }
        }
    }

return max;

}

int ValoreMinimo (int x[][DIMY]) {

int min=10;
int NumRighe;
int NumColonne;


for (NumRighe = 0; NumRighe < DIMX; NumRighe++)
    {
        for (NumColonne = 0; NumColonne < DIMY; NumColonne++)
        {
            if (x[NumRighe][NumColonne]<min) {
                min = x[NumRighe][NumColonne];
            }
        }
    }

return min;

}


int main()
{
    int Matrice[DIMX][DIMY];
    srand(time(NULL));

    GeneraMatrice(Matrice);

    printf("\nLa matrice e':\n");
    StampaMatrice (Matrice);

    printf("\nil valore maggiore e': %d", ValoreMassimo(Matrice));
    printf("\nil valore minimo e': %d",ValoreMinimo(Matrice));

    return 0;
}
