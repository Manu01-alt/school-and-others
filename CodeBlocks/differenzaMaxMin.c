#include <stdio.h>
#include <stdlib.h>


int differenzaMaxMin(int x, int y, int z) {
    int max=x;
    int min=x;
    int risultato;

    if (y > max) {
        max = y;
    }
    if (z> max) {
        max = z;
    }

    if (y < min) {
        min = y;
    }
    if (z < min) {
        min = z;
    }

    risultato = max - min;
    return risultato;
}

int main() {
    int num1, num2, num3;
    int differenza;

    printf("Inserisci tre numeri interi: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    differenza = differenzaMaxMin(num1, num2, num3);
    printf("La differenza tra il massimo e il minimo e': %d\n", differenza);

    return 0;
}
