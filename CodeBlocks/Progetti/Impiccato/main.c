#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ERRORS 6

// Funzione per disegnare l'impiccato
void drawHangman(int errors) {
    switch (errors) {
        case 0:
            printf("  +---+\n"
                   "  |   |\n"
                   "      |\n"
                   "      |\n"
                   "      |\n"
                   "      |\n"
                   "=========\n");
            break;
        case 1:
            printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   "      |\n"
                   "      |\n"
                   "      |\n"
                   "=========\n");
            break;
        case 2:
            printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   "  |   |\n"
                   "      |\n"
                   "      |\n"
                   "=========\n");
            break;
        case 3:
            printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   " /|   |\n"
                   "      |\n"
                   "      |\n"
                   "=========\n");
            break;
        case 4:
            printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   " /|\\  |\n"
                   "      |\n"
                   "      |\n"
                   "=========\n");
            break;
        case 5:
            printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   " /|\\  |\n"
                   " /    |\n"
                   "      |\n"
                   "=========\n");
            break;
        case 6:
            printf("  +---+\n"
                   "  |   |\n"
                   "  O   |\n"
                   " /|\\  |\n"
                   " / \\  |\n"
                   "      |\n"
                   "=========\n");
            break;
    }
}

// Funzione per aggiornare lo stato della parola
void updateWordState(const char* word, char* guessedWord, char guess) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (tolower(word[i]) == tolower(guess)) {
            guessedWord[i] = word[i];
        }
    }
}

// Controllo se la parola è completata
int isWordComplete(const char* guessedWord) {
    for (int i = 0; guessedWord[i] != '\0'; i++) {
        if (guessedWord[i] == '_') {
            return 0;
        }
    }
    return 1;
}

int main() {
    const char* word = "programmare"; // La parola segreta
    char guessedWord[50];
    int errors = 0;
    char guess;
    int found;

    // Inizializzazione dello stato della parola
    for (int i = 0; word[i] != '\0'; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[strlen(word)] = '\0';

    printf("Benvenuto nel gioco dell'impiccato!\n");

    while (errors < MAX_ERRORS) {
        drawHangman(errors);
        printf("Parola: %s\n", guessedWord);
        printf("Inserisci una lettera: ");
        scanf(" %c", &guess);

        // Controllo se la lettera è nella parola
        found = 0;
        for (int i = 0; word[i] != '\0'; i++) {
            if (tolower(word[i]) == tolower(guess)) {
                found = 1;
                break;
            }
        }

        if (found) {
            updateWordState(word, guessedWord, guess);
        } else {
            errors++;
        }

        if (isWordComplete(guessedWord)) {
            printf("Complimenti! Hai indovinato la parola: %s\n", word);
            return 0;
        }
    }

    drawHangman(errors);
    printf("Hai perso! La parola era: %s\n", word);

    return 0;
}
