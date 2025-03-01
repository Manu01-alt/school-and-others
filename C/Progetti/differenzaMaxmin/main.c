#include <stdio.h>
#include <stdlib.h>

int isNumeroPerfetto(int x)
{
    int sommaDivisori = 0;
    int risultato;
    int i;

    for (i = 1; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            sommaDivisori = sommaDivisori + i;
        }
    }

    if (sommaDivisori == x)
    {
        risultato = 1;
    }
    else
    {
        risultato = 0;

    }

    return risultato;
}

int main()
{
    int numero;

    printf("Inserisci un numero intero: ");
    scanf("%d", &numero);

    int risultato = isNumeroPerfetto(numero);

    if (risultato)
    {
        printf("%d e' un numero perfetto.\n", numero);
    }
    else
    {
        printf("%d non e' un numero perfetto.\n", numero);
    }

    return 0;
}
