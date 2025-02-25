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

int invertiArray(int x[SIZE]) {

    int i;
    int temp;

    for (i=0;i<SIZE/2;i++) {

        temp=x[i];
        x[i]=x[(SIZE-1)-i];
        x[(SIZE-1)-i]=temp;
    }

return 0;
}

int Contapari (int x[SIZE]) {

    int i;
    int c=0;

    for (i=0;i<SIZE;i++) {
        if (x[i]%2==0) {
            c++;
        }
    }


printf("\ni numeri pari sono: %d", c);

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

int main()
{

    int Array[SIZE]={0};
    srand(time(NULL));

    generaArray(Array);
    stampaArray(Array);
    invertiArray(Array);
    stampaArray(Array);
    Contapari(Array);
    return 0;
}
