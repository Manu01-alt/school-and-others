#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Matrice[2][3];
    int NumRighe;
    int NumColonne;


    for (NumColonne=0;NumColonne<2;NumColonne++) {
        for (NumRighe=0;NumRighe<3;NumRighe++) {
            printf("inserire elemento colonna %d e riga %d: ", NumColonne, NumRighe);
            scanf("%d", &Matrice[NumColonne][NumRighe]);
        }
    }

        printf("\nLa matrice inserita e':\n");
    for (NumColonne=0; NumColonne <2; NumColonne++) {
        for (NumRighe=0; NumRighe <3; NumRighe++) {
            printf("%d\t", Matrice[NumColonne][NumRighe]);
        }
        printf("\n");
    }


    return 0;
}
