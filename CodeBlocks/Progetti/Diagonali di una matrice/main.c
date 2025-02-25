#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int Matrice[6][6];
    int NumRighe, NumColonne;
    int somma = 0;
    int somma_secondaria = 0;
    srand(time(NULL));

    for (NumRighe = 0; NumRighe < 6; NumRighe++)
    {
        for (NumColonne = 0; NumColonne < 6; NumColonne++)
        {
            Matrice[NumRighe][NumColonne] = (rand() % 10) + 1;
        }
    }

    printf("\nLa matrice e':\n");
    for (NumRighe = 0; NumRighe < 6; NumRighe++)
    {
        for (NumColonne = 0; NumColonne < 6; NumColonne++)
        {
            printf("%d\t", Matrice[NumRighe][NumColonne]);
        }
        printf("\n");
    }

    for (NumRighe = 0; NumRighe < 6; NumRighe++)
    {
        for (NumColonne = 0; NumColonne < 6; NumColonne++)
        {
            if (NumRighe == NumColonne)
            {
                somma = somma_secondaria + Matrice[NumRighe][NumColonne];
            }
            if (NumRighe + NumColonne == 5)
            {
                somma_secondaria = somma_secondaria + Matrice[NumRighe][NumColonne];
            }
        }
    }


    printf("\nLa somma della diagonale principale e': %d", somma);
    printf("\nLa somma degli elementi della diagonale secondaria e': %d\n", somma_secondaria);

    return 0;
}
