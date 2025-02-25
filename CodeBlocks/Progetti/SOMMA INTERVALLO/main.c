#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int array[50] = {0};
    int i = 0, h = 0, k = 0;
    int somma = 0;
    srand(time(NULL));

    printf("Inserire il primo valore h: ");
    scanf("%d", &h);

    while (h < 0 || h >= 50) {
        printf("Valore di h non valido. Inserire un valore tra 0 e 49: ");
        scanf("%d", &h);
    }

    printf("Inserire il secondo valore k: ");
    scanf("%d", &k);

    while (k < 0 || k >= 50) {
        printf("Valore di k non valido. Inserire un valore tra 0 e 49: ");
        scanf("%d", &k);
    }
    if (k < h) {
        i = k;
        k = h;
        h = i;
    }
    for (i = 0; i < 50; i++) {
        array[i] = rand() % 20 + 1;
    }
    printf("\nArray generato:\n");
    for (i = 0; i < 50; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    for (i = h; i <= k; i++) {
        somma = somma + array[i];
    }
    printf("La somma degli elementi tra gli indici %d e %d e': %d\n", h, k, somma);

    return 0;
}
