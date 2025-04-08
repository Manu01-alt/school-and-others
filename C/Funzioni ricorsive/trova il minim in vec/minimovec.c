#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int trovaMinimo(int *vettore, int n)
{
    if (n == 1) {
        return vettore[0];
    }
    int min = trovaMinimo(vettore, n - 1);
    return (vettore[n - 1] < min) ? vettore[n - 1] : min;
}
    int vettore[DIM] = {7, 6, 2, 3, 4, 8, 5, 9, 6, 10};

    int main() {
    int minimo = trovaMinimo(vettore, DIM);

    printf("Il minimo del vettore è: %d\n", minimo);
    
return 0;
}