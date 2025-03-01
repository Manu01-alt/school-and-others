#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int MatriceA[3][2];
    int MatriceB[2][3];
    int MatriceC[3][3];
    int NumRighe;
    int NumColonne;
    int i;
    srand(time(NULL));

    for (NumColonne=0;NumColonne<2;NumColonne++) {
        for (NumRighe=0;NumRighe<3;NumRighe++) {
            MatriceA[NumRighe][NumColonne]=(rand() % 10)+1;
        }
    }

        printf("\nLa matrice A e':\n");
    for (NumColonne=0; NumColonne <3; NumColonne++) {
        for (NumRighe=0; NumRighe <2; NumRighe++) {
            printf("%d\t", MatriceA[NumColonne][NumRighe]);
        }
        printf("\n");
    }

    for (NumColonne=0;NumColonne<3;NumColonne++) {
        for (NumRighe=0;NumRighe<2;NumRighe++) {
            MatriceB[NumRighe][NumColonne]=(rand() % 10)+1;
        }
    }

          printf("\nLa matrice B e':\n");
    for (NumColonne=0; NumColonne <2; NumColonne++) {
        for (NumRighe=0; NumRighe <3; NumRighe++) {
            printf("%d\t", MatriceB[NumColonne][NumRighe]);
        }
        printf("\n");
    }

      for (NumColonne=0; NumColonne<3; NumColonne++) {
        for (NumRighe=0;NumRighe<3; NumRighe++) {
            MatriceC[NumRighe][NumColonne]=0;
        }
    }


    for (NumColonne=0;NumColonne<3;NumColonne++) {
        for (NumRighe=0;NumRighe<3;NumRighe++) {
                for (i=0;i<2;i++) {
            MatriceC[NumRighe][NumColonne]= MatriceC[NumRighe][NumColonne]+(MatriceA[NumRighe][i] * MatriceB[i][NumColonne]);
                }
        }
    }


          printf("\nLa matrice C ottenuta dal prodotto della matrice A e della matrice B e':\n");
    for (NumColonne=0; NumColonne <3; NumColonne++) {
        for (NumRighe=0; NumRighe <3; NumRighe++) {
            printf("%d\t", MatriceC[NumColonne][NumRighe]);
        }
        printf("\n");
    }


    return 0;
}
