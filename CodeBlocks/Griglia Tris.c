#include <stdio.h>
#include <stdlib.h>
int GeneraMatrice(char x[][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            x[i][j] = ' ';
        }
    }
    return 0;
}

int StampaMatrice (char x[][3]) {

int i,j;

printf("\nLa matrice e':\n");
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 3; i++)
        {
            printf(" %c", x[i][j]);
            if (i<2) {
                printf(" |");
            }
        }
        if (j<2) {
        printf("\n---+---+---\n");
        }
    }
return 0;
}

int main()
{
    char Matrice[3][3];

    GeneraMatrice(Matrice);
    StampaMatrice(Matrice);


    return 0;
}
