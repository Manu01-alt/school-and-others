//Gizzi Manuel 4CINF
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

struct CopyStats {
    unsigned int bytesCopied;
    unsigned int readErrors;
    unsigned int writeErrors;
};

int main(int argc, char *argv[]) {
    FILE *sorgente = fopen(argv[1], "rb");
    FILE *destinazione = fopen(argv[2], "wb");
    uint8_t buffer[256]; 
    size_t bytesRead; 
    struct CopyStats CopyStats = {0, 0, 0};
    
    // Controllo degli argomenti della riga di comando, se non sono 3 (nome programma + 2 file) esce con errore
    if (argc != 3) {
        fprintf(stderr, "Uso corretto: %s <file_sorgente> <file_destinazione>\n", argv[0]);
        return 1;
    }
    // Se fopen fallisce esce con errore
    if (sorgente == NULL || destinazione == NULL) {
        perror("Errore nell'apertura dei file");
        return 1;
    }

    // Ciclo di copia dei dati dal file sorgente al file destinazione
    while ((bytesRead = fread(buffer, sizeof(uint8_t), sizeof(buffer), sorgente))) {
        // Se i byte letti sono meno di quelli richiesti e non è EOF, c'è stato un errore di lettura
        if (bytesRead < sizeof(buffer) && !feof(sorgente)) {
            perror("Errore di lettura");
            CopyStats.readErrors++;
        }

        // Se i byte scritti sono meno di quelli letti, c'è stato un errore di scrittura
        size_t bytesWritten = fwrite(buffer, sizeof(uint8_t), bytesRead, destinazione);
        if (bytesWritten < bytesRead) {
            perror("Errore di scrittura");
            CopyStats.writeErrors++;
        }

        CopyStats.bytesCopied += bytesWritten;
    }

    //chiusura dei file
    fclose(sorgente);
    fclose(destinazione);

    printf
    // Stampa delle statistiche in output su stdout
    fprintf(stdout, "Bytes copiati: %u\n", CopyStats.bytesCopied);
    fprintf(stdout, "Errori di lettura: %u\n", CopyStats.readErrors);
    fprintf(stdout, "Errori di scrittura: %u\n", CopyStats.writeErrors);
    return 0;

}