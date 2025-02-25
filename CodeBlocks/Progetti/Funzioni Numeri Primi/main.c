#include <stdio.h>
#include <stdlib.h>

int isprimo(int x)
{
    int primo = 1;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            primo = 0;
        }
    }

    return primo;
}

int main()
{
   int num;
   int risultato;

   printf("inserisci numero:");
   scanf("%d", &num);

   risultato = isprimo(num);

   printf("risultato:%d", risultato);

    return 0;
}
