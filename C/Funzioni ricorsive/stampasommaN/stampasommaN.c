#include <stdio.h>
#include <stdlib.h>

int somma(int n)
{
    if (n == 0)
        return 0;
    
    return n + somma(n - 1);
}

int main()
{
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    printf("La somma dei numeri da 1 a %d è: %d\n", n, somma(n));
    return 0;
}