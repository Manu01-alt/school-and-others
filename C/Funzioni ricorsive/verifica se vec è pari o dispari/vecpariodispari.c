#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int verificaDispari(int *vettore, int n)
{
    if (vettore[n - 1] % 2 == 0)
        return 0; 

    if (n == 1)
        return 1; 

    return verificaDispari(vettore, n - 1);
}

int main()
{
    int vettore[DIM] = {3,5,7,9,11,13,15,17,19,21};
    int i;

    if (verificaDispari(vettore, DIM)==1)
        printf("Tutti gli elementi del vettore sono dispari.\n");
    else
        printf("Il vettore contiene almeno un numero pari.\n");

    return 0;
}
