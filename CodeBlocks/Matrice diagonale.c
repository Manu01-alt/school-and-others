#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Matrice[3][3];
    int NumRighe;
    int NumColonne;
    int c;

    for (NumColonne=0; NumColonne<3; NumColonne++)
    {
        for (NumRighe=0; NumRighe<3; NumRighe++)
        {
            printf("inserire elemento colonna %d e riga %d: ", NumColonne, NumRighe);
            scanf("%d", &Matrice[NumColonne][NumRighe]);
        }
    }

    printf("\nLa matrice inserita e':\n");
    for (NumColonne=0; NumColonne <3; NumColonne++)
    {
        for (NumRighe=0; NumRighe <3; NumRighe++)
        {
            printf("%d\t", Matrice[NumColonne][NumRighe]);
        }
        printf("\n");
    }

    for (NumColonne=0; NumColonne <3; NumColonne++)
    {
        for (NumRighe=0; NumRighe <3; NumRighe++)
        {

            if (NumColonne!=NumRighe)
            {
                        if (Matrice[NumRighe][NumColonne]!=0)
                        {
                            c=1;
                        }
                    }
                    else if (Matrice[NumRighe][NumColonne]==0)
                    {
                        c=1;
                    }
                }
            }

                    if (c==1)
            {
                printf("la matrice non e' diagonale");
            }
            else
            {
                printf("la matrice e' diagonale");
            }

        return 0;
}
