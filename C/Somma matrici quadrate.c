#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int MatriceA[3][3];
    int MatriceB[3][3];
    int MatriceC[3][3];
    int NumRighe;
    int NumColonne;
    srand(time(NULL));

    for (NumColonne=0;NumColonne<3;NumColonne++) {
        for (NumRighe=0;NumRighe<3;NumRighe++) {
            MatriceA[NumRighe][NumColonne]=(rand() % 10)+1;
        }
    }

        printf("\nLa matrice A e':\n");
    for (NumColonne=0; NumColonne <3; NumColonne++) {
        for (NumRighe=0; NumRighe <3; NumRighe++) {
            printf("%d\t", MatriceA[NumColonne][NumRighe]);
        }
        printf("\n");
    }

    for (NumColonne=0;NumColonne<3;NumColonne++) {
        for (NumRighe=0;NumRighe<3;NumRighe++) {
            MatriceB[NumRighe][NumColonne]=(rand() % 10)+1;
        }
    }

        printf("\nLa matrice B e':\n");
    for (NumColonne=0; NumColonne <3; NumColonne++) {
        for (NumRighe=0; NumRighe <3; NumRighe++) {
            printf("%d\t", MatriceB[NumColonne][NumRighe]);
        }
        printf("\n");
    }

    for (NumColonne=0;NumColonne<3;NumColonne++) {
        for (NumRighe=0;NumRighe<3;NumRighe++) {
            MatriceC[NumRighe][NumColonne]= MatriceA[NumRighe][NumColonne] + MatriceB[NumRighe][NumColonne];
        }
    }


        printf("\nLa matrice C ottenuta dalla somma della matrice A e della matrice B e':\n");
    for (NumColonne=0; NumColonne <3; NumColonne++) {
        for (NumRighe=0; NumRighe <3; NumRighe++) {
            printf("%d\t", MatriceC[NumColonne][NumRighe]);
        }
        printf("\n");
    }

    return 0;
}
