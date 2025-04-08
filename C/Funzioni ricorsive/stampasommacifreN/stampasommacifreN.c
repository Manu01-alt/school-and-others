#include <stdio.h>
#include <stdlib.h>

int sommaCifre(int n) 
{
    if (n == 0)
        return 0;
    
    return n % 10 + sommaCifre(n / 10);
}

int main()
{
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    printf("La somma delle cifre di %d è: %d\n", n, sommaCifre(n));
    return 0;
}
