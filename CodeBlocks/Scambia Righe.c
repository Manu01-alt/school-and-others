#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Matrice[4][4];
    int NumRighe, NumColonne;
    int temp=0;


    for (NumRighe = 0; NumRighe < 4; NumRighe++)
    {
        for (NumColonne = 0; NumColonne < 4; NumColonne++)
        {
            Matrice[NumRighe][NumColonne] = (rand() % 10) + 1;
        }
    }


    printf("\nLa matrice e':\n");
    for (NumRighe = 0; NumRighe < 4; NumRighe++)
    {
        for (NumColonne = 0; NumColonne < 4; NumColonne++)
        {
            printf("%d\t", Matrice[NumRighe][NumColonne]);
        }
        printf("\n");
    }

   for (NumRighe = 0; NumRighe < 4; NumRighe = NumRighe + 2) {
        for (NumColonne = 0; NumColonne < 4; NumColonne++) {
        temp = Matrice[NumRighe][NumColonne];
         Matrice[NumRighe][NumColonne]=Matrice[NumRighe+1][NumColonne];
         Matrice[NumRighe+1][NumColonne]=temp;
        }
   }

     printf("\nLa matrice dopo lo scambio e':\n");
    for (NumRighe = 0; NumRighe < 4; NumRighe++)
    {
        for (NumColonne = 0; NumColonne < 4; NumColonne++)
        {
            printf("%d\t", Matrice[NumRighe][NumColonne]);
        }
        printf("\n");
    }
    return 0;
}
