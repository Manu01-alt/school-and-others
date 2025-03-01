#include <stdio.h>
#include <stdlib.h>

int Tris(char x[][3]) {
    int i;
    for (i = 0; i < 3; i++) {
        if ((x[i][0] == 'X' && x[i][1] == 'X' && x[i][2] == 'X') ||
            (x[0][i] == 'X' && x[1][i] == 'X' && x[2][i] == 'X')) {
            printf("Tris X!\n");
            return 1;
        }
        if ((x[i][0] == 'O' && x[i][1] == 'O' && x[i][2] == 'O') ||
            (x[0][i] == 'O' && x[1][i] == 'O' && x[2][i] == 'O')) {
            printf("Tris O!\n");
            return 1;
        }
    }
    if ((x[0][0] == 'X' && x[1][1] == 'X' && x[2][2] == 'X') ||
        (x[0][2] == 'X' && x[1][1] == 'X' && x[2][0] == 'X')) {
        printf("Tris X!\n");
        return 1;
    }
    if ((x[0][0] == 'O' && x[1][1] == 'O' && x[2][2] == 'O') ||
        (x[0][2] == 'O' && x[1][1] == 'O' && x[2][0] == 'O')) {
        printf("Tris O!\n");
        return 1;
    }
    return 0;
}

void GeneraMatrice(char x[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            x[i][j] = ' ';
        }
    }
}

void StampaMatrice(char x[][3]) {
    printf("\nLa matrice e':\n");
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            printf(" %c", x[i][j]);
            if (i < 2) printf(" |");
        }
        if (j < 2) printf("\n---+---+---\n");
    }
    printf("\n");
}

void ControlloRigaColonna(int *riga, int *colonna) {
    do {
        printf("Inserire riga (0-2): ");
        scanf("%d", riga);
    } while (*riga < 0 || *riga > 2);

    do {
        printf("Inserire colonna (0-2): ");
        scanf("%d", colonna);
    } while (*colonna < 0 || *colonna > 2);
}

void ControlloPosizione(char x[][3], int *riga, int *colonna) {
    while (x[*colonna][*riga] != ' ') {
        printf("Errore! Posizione occupata\n");
        ControlloRigaColonna(riga, colonna);
    }
}

void InserimentoValori(char x[][3]) {
    int riga, colonna;
    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            printf("\nX] Inserire riga: ");
            ControlloRigaColonna(&riga, &colonna);
            ControlloPosizione(x, &riga, &colonna);
            x[colonna][riga] = 'X';
        } else {
            printf("\nO] Inserire riga: ");
            ControlloRigaColonna(&riga, &colonna);
            ControlloPosizione(x, &riga, &colonna);
            x[colonna][riga] = 'O';
        }
        StampaMatrice(x);
        if (Tris(x)) return;
    }
}

int main() {
    char Matrice[3][3];
    GeneraMatrice(Matrice);
    StampaMatrice(Matrice);
    InserimentoValori(Matrice);
    return 0;
}
