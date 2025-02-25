#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIMX 5
#define DIMY 4

int GeneraMatrice(int x[][DIMY]) {
    int NumRighe, NumColonne;
    for (NumRighe = 0; NumRighe < DIMX; NumRighe++) {
        for (NumColonne = 0; NumColonne < DIMY; NumColonne++) {
            x[NumRighe][NumColonne] = rand() % 10 + 1;
        }
    }
    return 0;
}

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

int SommaRighe(int x[][DIMY], int y[]) {
    int NumRighe, NumColonne;
    for (NumRighe = 0; NumRighe < DIMX; NumRighe++) {
        y[NumRighe] = 0;  // Inizializza la somma della riga
        for (NumColonne = 0; NumColonne < DIMY; NumColonne++) {
            y[NumRighe] += x[NumRighe][NumColonne];  // Somma gli elementi della riga
        }
    }
    return 0;
}

int SommaColonne(int x[][DIMY], int y[]) {
    int NumRighe, NumColonne;
    for (NumColonne = 0; NumColonne < DIMY; NumColonne++) {
        y[NumColonne] = 0;  // Inizializza la somma della colonna
        for (NumRighe = 0; NumRighe < DIMX; NumRighe++) {
            y[NumColonne] += x[NumRighe][NumColonne];  // Somma gli elementi della colonna
        }
    }
    return 0;
}

int main() {
    int matrice[DIMX][DIMY];
    int sommaRighe[DIMX];
    int sommaColonne[DIMY];
    int NumRighe;
    int NumColonne;

    srand(time(NULL));
    GeneraMatrice(matrice);

    printf("Matrice generata:\n");
    StampaMatrice(matrice);

    SommaRighe(matrice, sommaRighe);
    SommaColonne(matrice, sommaColonne);

    printf("\nSomma di ogni riga:\n");
    for (NumRighe = 0; NumRighe < DIMX; NumRighe++) {
        printf("Riga %d: %d\n", NumRighe, sommaRighe[NumRighe]);
    }

    printf("\nSomma di ogni colonna:\n");
    for (NumColonne = 0; NumColonne < DIMY; NumColonne++) {
        printf("Colonna %d: %d\n", NumColonne, sommaColonne[NumColonne]);
    }

    return 0;
}
