//GIZZI MANUEL
#include "MyLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Global variable for the question index
int indice = 1;

int main()
{
    int flag = 1;

    // The main loop of the program contains a switch-case that allows navigation through the menu
    while (flag)
    {
        char scelta;
        printf("\n--------------------------------\nScegliere un opzione:\nA - Aggiungi domanda\nS - Somministra questionario\nC - Cancella domanda\nF - Pulisci File\nX - Termina.\n>");
        fflush(stdin);
        scanf("%c", &scelta);

        switch(toupper(scelta))
        {
        case 'A' :
            aggiungi_domanda();
            break;
        case 'S' :
            somministra_questionario();
            break;
        /*case 'C':
            cancella_domanda;
            break;*/
        case 'X':
            flag = 0;
            break;
        case 'F':
        {
            FILE *file_handle = fopen("questionario.txt","w");
            fclose(file_handle);
            printf("\nPulizia del file completata\n");
        }
        }
    }

    return 0;
}
