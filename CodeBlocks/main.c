#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int generaArray(int x[SIZE]) {
    int i;

    for (i=0;i<SIZE;i++) {
        x[i]=rand() % 20+1;
    }
   return 0;
}

int stampaArray(int x[SIZE]) {
    int i;

    printf("\nArray:");
    for (i=0;i<SIZE;i++) {
        printf("%d, ", x[i]);
    }
   return 0;
}

int sommaArray(int x[SIZE]) {

    int i;
    int somma=0;
    for (i=0;i<SIZE;i++) {
        somma = somma + x[i];
    }
return somma;
}
int main()
{
    int Array[SIZE]={0};
    int risultato;
    srand(time(NULL));

    generaArray(Array);
    stampaArray(Array);
    risultato=sommaArray(Array);

    printf("\nla somma degli elementi dell'Array e':%d", risultato);

    return 0;
}
