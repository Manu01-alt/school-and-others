#include <stdio.h>
#include <stdlib.h>

void stampa(int n)
{
    if (n == 0)
        return;
    stampa(n - 1);
    printf("%d\n", n);
}

int main()
{
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    stampa(n);
    return 0;
}