//GIZZI MANUEL 3CINF 07/03/25
#include <stdio.h>  // Per printf e scanf
#include <stdlib.h> // Per srand e rand
#include <time.h>   // Per time(NULL), inizializzazione del seed

int main()
{
    int numero, dadi, facce_dadi;
    srand(time(NULL));

    printf("Inserire il numero di lanci: ");
    scanf("%d", &numero);
    printf("Inserire il numero di dadi: ");
    scanf("%d", &dadi);
    printf("Inserire il numero di facce: ");
    scanf("%d", &facce_dadi);

    // Dichiaro l'array delle frequenze
    int frequenze[facce_dadi + 1];

    // Inizializzo le frequenze a zero
    for (int j = 1; j <= facce_dadi; j++)
    {
        frequenze[j] = 0;
    }


    //Ciclo for per la gestione dei dadi
    for (int j = 0; j < dadi; j++)
    {
        printf("\nDado %d:\n", j + 1);

        //Azzero le frequenze
        for (int j = 1; j <= facce_dadi; j++)
        {
            frequenze[j] = 0;
        }

        //Ciclo for per la gestione dei lanci
        for (int i = 0; i < numero; i++)
        {
            int lancio = rand() % facce_dadi + 1; // Numero casuale tra 1 e facce_dadi
            frequenze[lancio]++; // Aggiorna la frequenza del numero generato
        }
        // Stampa delle frequenze totali
        printf("\nFrequenze dei numeri:\n");
        for (int i = 1; i <= facce_dadi; i++)
        {
            printf("Numero %d: %d volte\n", i, frequenze[i]);
        }
    }

    return 0;
}
