#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Matrice[3][3];
    int NumRighe, NumColonne;
    int f=1;


    for (NumColonne=0; NumColonne<3; NumColonne++)
    {
        for (NumRighe=0; NumRighe<3; NumRighe++)
        {
            printf("inserire elemento colonna %d e riga %d: ", NumColonne, NumRighe);
            scanf("%d", &Matrice[NumColonne][NumRighe]);
        }
    }

    printf("\nLa matrice e':\n");
    for (NumRighe = 0; NumRighe < 3; NumRighe++)
    {
        for (NumColonne = 0; NumColonne < 3; NumColonne++)
        {
            printf("%d\t", Matrice[NumRighe][NumColonne]);
        }
        printf("\n");
    }

   for (NumRighe = 0; NumRighe < 3; NumRighe++) {
        for (NumColonne = 0; NumColonne < 3; NumColonne++) {
            if (Matrice[NumRighe][NumColonne] != Matrice[NumColonne][NumRighe]) {
                f = 0;
            }
        }
    }
    if (f == 1) {
        printf("\nLa matrice e' simmetrica\n");
    } else {
        printf("\nLa matrice non e' simmetrica\n");
    }
    return 0;
}
