#include <stdio.h>
#include <stdlib.h>
#define N 4

int InserisciMatrice(int x[][N]) {

int i,j;

for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("Elemento riga:%d colonna:%d : ", i, j);
            scanf("%d", &x[i][j]);
        }
    }
return 0;
}

int StampaMatrice (int x[][N]) {

int i,j;

printf("\nLa matrice e':\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d\t", x[i][j]);
        }
        printf("\n");
    }
return 0;
}

int main()
{
    int Matrice[N][N];
    int i, j;
    int c = 1;
    int f = 1;

    InserisciMatrice(Matrice);

    StampaMatrice(Matrice);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (j < i && Matrice[i][j] != 0)
            {
                c = 0;
            }
            if (j > i && Matrice[i][j] != 0)
            {
                f = 0;
            }
        }
    }

    if (c==1 && f==1)
    {
        printf("\nLa matrice e' sia triangolare superiore che inferiore (matrice diagonale).\n");
    }
    else if (f==1)
    {
        printf("\nLa matrice e' triangolare superiore.\n");
    }
    else if (c==1)
    {
        printf("\nLa matrice e' triangolare inferiore.\n");
    }
    else
    {
        printf("\nLa matrice non e' triangolare superiore ne' inferiore.\n");
    }

    return 0;
}
