#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "MyLib.h"
void aggiungi_domanda(void)
{

    FILE *file_handle = fopen("questionario.txt","a");
    int i,e;
    char* domanda = calloc(1,250);
    char* opzione = calloc(1,50);
    char giusta;
    char c = 65;

    printf("\nInserire domanda:");

    while ((e = getchar()) != '\n');  //pulisce il buffer
    fgets(domanda, 250, stdin);

    fprintf(file_handle,"%d. %s",indice,domanda);

    printf("Inserire le 4 opzioni:\n");

    for (i=0; i<4; i++)
    {
        fgets(opzione, 250, stdin);
        fprintf(file_handle,"%c:%s",c,opzione);
        c++;
    }

    printf("Inserire l'opzione corretta\n");

    scanf("%c",&giusta);
    fprintf(file_handle,"%c\n",toupper(giusta));

    fclose(file_handle);
    indice++;
    free(domanda);
    free(opzione);
}

void somministra_questionario(void)
{
    FILE *file_handle = fopen("questionario.txt","r");
    char risposta;
    char line[250];
    size_t len = sizeof(line);
    int punteggio = 0;

    while (fgets(line,len,file_handle) != NULL)
    {
        fflush(stdin);
        for (int i = 0; i < 5; i++)
        {
            printf("%s",line);
            fgets(line,len,file_handle);
        }

        char correct = line[0];

        printf("Inserire risposta corretta:");
        scanf("%c",&risposta);

        if (toupper(risposta) != correct )
        {
            printf("\nRisposta errata.\n");
        }
        else
        {
            printf("\nRisposta corretta.\n");
            punteggio++;
            printf("\nPunteggio: %d\n\n", punteggio);
        }

    }
    fclose(file_handle);
}






