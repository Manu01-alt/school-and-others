#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GeneraMatrice(char x[][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            x[i][j] = ' ';
        }
    }
}

void StampaMatrice(char x[][5]) {
    printf("\nLa matrice e':\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf(" %c ", x[i][j]);
            if (j < 4) printf("|");
        }
        printf("\n");
        if (i < 4) {
            printf("---+---+---+---+---\n");
        }
    }
    printf("\n");
}

int CalcolaDistanza(int tesoroRiga, int tesoroColonna, int giocatoreRiga, int giocatoreColonna) {

    int distanza = abs(tesoroRiga - giocatoreRiga) + abs(tesoroColonna - giocatoreColonna);

    if (distanza == 0) {
        printf("Congratulazioni! Hai trovato il tesoro!\n");
        return 1;
    } else if (distanza == 1) {
        printf("Molto vicino! Il tesoro e' a 1 cella di distanza.\n");
    } else if (distanza == 2) {
        printf("Vicino! Il tesoro e' a 2 celle di distanza.\n");
    } else {
        printf("Lontano! Il tesoro e' a piu' di 2 celle di distanza.\n");
    }
    return 0;
}

int main() {
    char mat[5][5];
    int tesoroRiga, tesoroColonna;
    int giocatoreRiga, giocatoreColonna;
    int tentativi = 0;

    srand(time(NULL));

    tesoroRiga = rand() % 4+0;
    tesoroColonna = rand() % 4+0;

    GeneraMatrice(mat);

    printf("Benvenuto nel gioco del tesoro! La griglia e' 5x5.\n");

    while (1) {
        tentativi++;

        StampaMatrice(mat);

        printf("Tentativo %d - Inserisci la riga (0-4): ", tentativi);
        scanf("%d", &giocatoreRiga);

        while (giocatoreRiga < 0 || giocatoreRiga > 4) {
            printf("Errore: la riga deve essere compresa tra 0 e 4. Riprova: ");
            scanf("%d", &giocatoreRiga);
        }

        printf("Inserisci la colonna (0-4): ");
        scanf("%d", &giocatoreColonna);

        while (giocatoreColonna < 0 || giocatoreColonna > 4) {
            printf("Errore: la colonna deve essere compresa tra 0 e 4. Riprova: ");
            scanf("%d", &giocatoreColonna);
        }

        mat[giocatoreRiga][giocatoreColonna] = 'X';

        if (CalcolaDistanza(tesoroRiga, tesoroColonna, giocatoreRiga, giocatoreColonna) == 1) {
            break;
        }
    }

    printf("Hai trovato il tesoro in %d tentativi!\n", tentativi);

    return 0;
}
