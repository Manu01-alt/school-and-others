#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int array[50]={0};
    int compatto[50]={0};
    int j, i;
    int ripetuto;

    srand(time(NULL));

    for (i=0;i<50;i++) {
        array[i]=rand () % 20 + 1;
    }

    printf("Array generato:\n");
    for (i=0;i<50;i++) {
        printf("%d ", array[i]);
    }
    for (i=0;i<50;i++) {
        for (j=0;j<50;j++) {
            if (array[i]==array[j]) {
                ripetuto=1;
                break;
            }
        }
        if (ripetuto==0) {
            compatto[i]=array[i];
        }

    }
    printf("\nArray compattato:\n");
    for (i=0;i<50;i++) {
            if (compatto[i]!=0) {
             printf("%d ", compatto[i]);
            }
    }
    return 0;
}
