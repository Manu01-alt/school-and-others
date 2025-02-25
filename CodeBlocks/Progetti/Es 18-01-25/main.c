#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Matrice[10][10];
    int NumRighe;
    int NumColonne;

    for (NumColonne=0; NumColonne <10; NumColonne++)
    {
        for (NumRighe=0; NumRighe <10; NumRighe++)
        {
            Matrice[NumRighe][NumColonne]=(NumRighe)*(NumColonne);
        }
    }
      printf("\nLa matrice inserita e':\n");
    for (NumColonne=0; NumColonne <10; NumColonne++)
    {
        for (NumRighe=0; NumRighe <10; NumRighe++)
        {
            printf("%d\t", Matrice[NumColonne][NumRighe]);
        }
        printf("\n");
    }


        return 0;
}
