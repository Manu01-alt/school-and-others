#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int Matrice[6][6];
    int NumRighe, NumColonne;
    int num;
    int c;
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


    printf("Inserire il numero da cercare: ");
    scanf("%d", &num);


    for (NumRighe = 0; NumRighe < 6; NumRighe++) {
        for (NumColonne = 0; NumColonne < 6; NumColonne++) {
            if (num == Matrice[NumRighe][NumColonne]) {
                printf("\nIl numero e' presente nella riga: %d e colonna: %d", NumRighe, NumColonne);
                c = 1;
            }
        }
    }

    if (c==0) {
        printf("\nIl numero non e' presente nella matrice. :(");
    }

    return 0;
}
