#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIMX 4
#define DIMY 4

int StampaMatrice(int x[][DIMY]) {
    int NumRighe, NumColonne;

    for (NumRighe = 0; NumRighe < DIMX; NumRighe++) {
        for (NumColonne = 0; NumColonne < DIMY; NumColonne++) {
            printf("%d\t", x[NumRighe][NumColonne]);
        }
        printf("\n");
    }
    return 0;
}

int GeneraMatrice(int x[][DIMY]) {
    int NumRighe, NumColonne;

    for (NumRighe = 0; NumRighe < DIMX; NumRighe++) {
        for (NumColonne = 0; NumColonne < DIMY; NumColonne++) {
            x[NumRighe][NumColonne] = (rand() % 10) + 1;
        }
    }
    return 0;
}

int TrasponiMatrice(int x[][DIMY], int y[][DIMY]) {
    int NumRighe, NumColonne;

    for (NumRighe = 0; NumRighe < DIMX; NumRighe++) {
        for (NumColonne = 0; NumColonne < DIMY; NumColonne++) {
            y[NumColonne][NumRighe] = x[NumRighe][NumColonne];
        }
    }
    return 0;
}

int InvertiColonne(int x[][DIMY]) {
    int NumRighe, NumColonne, temp;

    for (NumRighe = 0; NumRighe < DIMX; NumRighe++) {
        for (NumColonne = 0; NumColonne < DIMY / 2; NumColonne++) {

            temp = x[NumRighe][NumColonne];
            x[NumRighe][NumColonne] = x[NumRighe][DIMY - NumColonne - 1];
            x[NumRighe][DIMY - NumColonne - 1] = temp;
        }
    }
    return 0;
}

int RuotaMatrice(int x[][DIMY], int y[][DIMY]) {

    TrasponiMatrice(x, y);


    InvertiColonne(y);

    return 0;
}

int main() {
    int Matrice[DIMX][DIMY];
    int MatriceRuotata[DIMX][DIMY];
    srand(time(NULL));


    GeneraMatrice(Matrice);

    printf("\nLa matrice originale è:\n");
    StampaMatrice(Matrice);

    RuotaMatrice(Matrice, MatriceRuotata);

    printf("\nLa matrice ruotata di 90 gradi è:\n");
    StampaMatrice(MatriceRuotata);

    return 0;
}
