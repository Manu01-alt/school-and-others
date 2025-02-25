#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int Matrice[6][6];
    int NumRighe, NumColonne;
    int somma;
    int somma_secondaria;
    srand(time(NULL));

    for (NumRighe = 0; NumRighe < 6; NumRighe++) {
        for (NumColonne = 0; NumColonne < 6; NumColonne++) {
            Matrice[NumRighe][NumColonne] = (rand() % 10) + 1;
        }
    }

    printf("\nLa matrice e':\n");
    for (NumRighe = 0; NumRighe < 6; NumRighe++) {
        for (NumColonne = 0; NumColonne < 6; NumColonne++) {
            printf("%d\t", Matrice[NumRighe][NumColonne]);
        }
        printf("\n");
    }


    for (NumRighe = 0; NumRighe < 6; NumRighe++) {
        for (NumColonne = 0; NumColonne < 6; NumColonne++) {
            if (NumRighe==NumColonne) {
                somma = somma + Matrice[NumRighe][NumColonne];
            }
            else if (NumRighe + NumColonne == 6 - 1) {
                somma_secondaria = somma_secondaria + Matrice[NumRighe][NumColonne];
            }
        }
    }

    printf("la somma della diagonale principale e':%d \nla somma degli elementi della secondaria e':%d",somma, somma_secondaria);

    return 0;
}
