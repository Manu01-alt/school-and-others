#include <stdio.h>
#include <stdlib.h>

int cifraMaggiore(int x) {

    int cifraMax = 0;
    int cifra;

    while (x > 0) {
         cifra = x % 10;
        if (cifra > cifraMax) {
            cifraMax = cifra;
        }
        x = x/ 10;
    }

    return cifraMax;
}

int main() {
    int numero;

    printf("Inserisci un numero intero: ");
    scanf("%d", &numero);

    int risultato = cifraMaggiore(numero);
    printf("La cifra piu' alta e': %d\n", risultato);

    return 0;
}
