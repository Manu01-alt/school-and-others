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
        printf("\n--------------------------------\nScegliere un opzione:\nA - Aggiungi domanda\nS - Somministra questionario\nC - Cancella domanda\nX - Termina.\n>");
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
        case 'C':
            cancella_domanda();
            break;
        case 'X':
            printf("\nBye!!\n");
            flag = 0;
            break;
        }
    }

    return 0;
}
