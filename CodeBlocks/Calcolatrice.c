#include <stdio.h>
#include <stdlib.h>


int Calcolatrice (int x, int y, char z) {

    int calcolo;

    if (z == '*') {
        calcolo = x * y;
    }
    else if (z == '+') {
        calcolo = x + y;
    }
    else if (z == '/') {
            if (y == 0) {
             calcolo = 0;
            }
            else {
             calcolo = x / y;
            }
    }
    else if (z == '-') {
        calcolo = x - y;
    }
    return calcolo;

}

int main() {
    int num1, num2;
    char operazione;
    int risultato;

    printf("Inserisci due numeri interi: ");
    scanf("%d %d", &num1, &num2);

    printf("inserisci operazione: ");
    scanf(" %c", &operazione);

    risultato = Calcolatrice(num1,num2,operazione);

    while (risultato == 0 && operazione == '/') {
        printf("si e' verificato un errore, inserisci un valore valido per il divisore: ");
        scanf("%d", &num2);
        risultato = Calcolatrice(num1,num2,operazione);
    }

    printf("il risultato e': %d", risultato);

    return 0;
}
