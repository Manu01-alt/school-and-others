// Questo file è stato creato con l'editor di testo "Visual Studio Code" e non con "CodeBlocks"
//Questo file sarà un gioco basato sul random
// il programma tira due dadi e somma i risultati, se il numero scelto dall'utente è uguale alla somma dei due dadi, l'utente vince
// se il numero scelto dall'utente è diverso dalla somma dei due dadi, l'utente perde
// l'utente ha un budget iniziale di 500 euro, se vince il budget aumenta di 100 euro, se perde il budget diminuisce di 100 euro
// il gioco termina quando il budget è uguale a 0
// il gioco è in italiano

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int budget = 500;
    int scelta;
    int somma;
    int dado1;
    int dado2;
    srand(time(NULL));
    printf("Benvenuto al gioco dei dadi\n\n");
    printf("Il tuo budget iniziale e di 500 euro\n");
    printf("Il gioco termina quando il tuo budget e uguale a 0\n");
    printf("Buona fortuna\n\n");
    while (budget > 0)
    {
        printf("Inserisci un numero tra 2 e 12\n");
        scanf("%d", &scelta);
        if (scelta < 2 || scelta > 12)
        {
            printf("Il numero inserito non e valido\n\n");
            continue;
        }
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
        somma = dado1 + dado2;
        printf("Il risultato del primo dado e %d\n", dado1);
        printf("Il risultato del secondo dado e %d\n", dado2);
        printf("La somma dei due dadi e %d\n\n", somma);
        if (scelta == somma)
        {
            budget += 100;
            printf("Hai vinto\n");
            printf("Il tuo budget attuale e di %d euro\n\n", budget);
        }
        else
        {
            budget -= 100;
            printf("Hai perso\n");
            printf("Il tuo budget attuale e di %d euro\n\n", budget);
        }
    }
    printf("Hai perso\n");
    printf("Il tuo budget e uguale a 0\n");
    system("pause");
    return 0;
}
