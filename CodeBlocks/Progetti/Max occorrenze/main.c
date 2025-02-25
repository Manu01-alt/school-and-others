#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int array[10];
    int ripetuto[21] = {0};
    int max = 0;
    int i;

    srand(time(NULL));


    printf("Array generato: ");
    for (i = 0; i < 10; i++) {
        array[i] = rand() % 20 + 1;
        printf("%d ", array[i]);
    }


    for (i = 0; i < 10; i++)
        {
        ripetuto[array[i]]++;
        }


    for (i = 1; i <= 20; i++)
    {
        if (ripetuto[i] > ripetuto[max]) {
            max = i;
        }
    }

    printf("\nIl numero che si ripete e': %d\n", max);

    return 0;
}
