// Questo programma converte un numero decimale in binario
// utilizzando la ricorsione. La funzione `conversione2N` divide il numero

#include <stdio.h>
#include <stdlib.h>


int conversione2N(int n)
{
    if (n == 0)
        return 0;

    return ((n & 1) ? 1 : 0) + 10 * conversione2N(n >> 1);
}

int main ()
{
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    
    if (n == 0) {
        printf("0 in binario è 0\n");
    } else {
        printf("Il numero %d in binario è: %d\n", n, conversione2N(n));
    }
    
    return 0;
}