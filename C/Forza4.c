#include <stdio.h>
#include <stdlib.h>
#define DIMX 6
#define DIMY 7

void Inserimento(char matrice[][DIMY], char var)
{
    int righe = 5, colonna = 0, f = 1;

    printf("\nE' il turno di %c\n", var);
    printf("Inserire la colonna dove vuoi giocare: ");
    scanf("%d", &colonna);

    while (colonna < 1 || colonna > DIMY)
    {
        printf("Colonna non valida, inserire un numero tra 1 e 7: ");
        scanf("%d", &colonna);
    }

    while (matrice[0][colonna - 1] != ' ')
    {
        printf("La colonna %d e' piena, scegliere un'altra colonna: ", colonna);
        scanf("%d", &colonna);

        while (colonna < 1 || colonna > DIMY)
        {
            printf("Colonna non valida, inserire un numero tra 1 e 7: ");
            scanf("%d", &colonna);
        }
    }

    while (f == 1)
    {
        if (matrice[righe][colonna - 1] == ' ')
        {
            matrice[righe][colonna - 1] = var;
            f = 0;
        }
        else
        {
            righe--;
        }
    }

}

int Forza4(char matrice[][DIMY], char var)
{
    for (int i = 0; i < DIMX; i++)
    {
        for (int j = 0; j < DIMY - 3; j++)
        {
            if (matrice[i][j] == var && matrice[i][j + 1] == var && matrice[i][j + 2] == var && matrice[i][j + 3] == var)
                return 1;
        }
    }

    for (int i = 0; i < DIMX - 3; i++)
    {
        for (int j = 0; j < DIMY; j++)
        {
            if (matrice[i][j] == var && matrice[i + 1][j] == var && matrice[i + 2][j] == var && matrice[i + 3][j] == var)
                return 1;
        }
    }

    for (int i = 0; i < DIMX - 3; i++)
    {
        for (int j = 0; j < DIMY - 3; j++)
        {
            if (matrice[i][j] == var && matrice[i + 1][j + 1] == var && matrice[i + 2][j + 2] == var && matrice[i + 3][j + 3] == var)
                return 1;
        }
    }

    for (int i = 3; i < DIMX; i++)
    {
        for (int j = 0; j < DIMY - 3; j++)
        {
            if (matrice[i][j] == var && matrice[i - 1][j + 1] == var && matrice[i - 2][j + 2] == var && matrice[i - 3][j + 3] == var)
                return 1;
        }
    }

    return 0;
}

void stampa_matrice(char matrice[][DIMY])
{
    for (int i = 0; i < DIMX; i++)
    {
        for (int j = 0; j < DIMY - 1; j++)
        {
            printf("  %c  |", matrice[i][j]);
        }
        printf("  %c  ", matrice[i][DIMY - 1]);
        if (i < DIMX - 1)
        {
            printf("\n-----+-----+-----+-----+-----+-----+-----\n");
        }
    }
}

int main()
{
    int i, j, turno = 0, vittoria = 0;
    char matrice[DIMX][DIMY], var;

    for (i = 0; i < DIMX; i++)
    {
        for (j = 0; j < DIMY; j++)
        {
            matrice[i][j] = ' ';
        }
    }

    while (vittoria == 0)
    {
        if (turno % 2 == 0)
        {
            var = 'X';
        }
        else
        {
            var = 'O';
        }

        stampa_matrice(matrice);
        Inserimento(matrice, var);

        vittoria = Forza4(matrice, var);
        if (vittoria == 1)
        {
            stampa_matrice(matrice);
            printf("\nCongratulazioni, %c ha vinto!\n", var);
            return 0;
        }

        turno++;
    }
}
