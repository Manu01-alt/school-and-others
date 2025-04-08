// Questo programma inverte un vettore
// utilizzando la ricorsione. La funzione `invertiVettore` scambia gli elementi

#include <stdio.h>
#include <stdlib.h>
#define dim 10

void invertiVettore(int *vettore, int inizio, int fine)
{
    if (inizio >= fine)
        return;

    // Scambia gli elementi
    int temp = vettore[inizio];
    vettore[inizio] = vettore[fine];
    vettore[fine] = temp;

    // Chiamata ricorsiva
    invertiVettore(vettore, inizio + 1, fine - 1);
}

int main()
{
    int vettore[dim] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    invertiVettore(vettore, 0, dim - 1);

    printf("Vettore invertito:\n");
    for (int i = 0; i < dim; i++) {
        printf("%d ", vettore[i]);
    }
    printf("\n");

    return 0;
}
