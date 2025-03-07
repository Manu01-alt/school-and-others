//GIZZI MANUEL 3CINF 07/03/25
#include <stdio.h> //per il printf e scanf

int main() {

    int numero, bit, shift;

    printf("Inserire un numero intero: ");
    scanf("%d", &numero);

    printf("la codifica binaria di %d e': ", numero);

    //ciclo for di 7 per stampare valori da 8 bit
    for (int i = 7; i >= 0; i--) {

        //eseguo uno shift a destra del numero di "i" posizioni
       shift = numero >> i;
        //faccio il mascheramento con l'and per ricavare il bit
        bit = shift & 1;

        printf("%d", bit); //Stampa del bit
    }

    return 0;
}
