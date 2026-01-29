#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int counter;
} InfoFile;

void conta_struct(InfoFile *s) {
    s->counter++;
}


int main(int argc, char** argv) {

    if (argc == 1) {
        perror("Errore! Parametri errati");
    }
    else if (!strcmp(argv[1],"-h") || !strcmp(argv[1],"--help")) {
        printf("~ Come usare il mio bellissimo programmino :D\n");
        printf("~ > ./programma [File1].txt [File2].txt\n");
        printf("~ Se si desidera stampare il contenuto del file sorgente a schermo: \n");
        printf("~ > ./programma -s [File1].txt\n");
        return 1;
    }
    else if (!strcmp(argv[1], "-s")) {
        FILE *file_handle = fopen(argv[2], "r");
        char line[256];
        while(fgets(line,sizeof(line),file_handle)) {
            fputs(line,stdout);
        }
        fclose(file_handle);
        printf("\n=====================================\n");
        printf("\n\nStampa avvenuta con successo!\n\n");
        return 2;
    }
    else {
        FILE *sorgente = fopen(argv[1],"r");
        FILE *destinazione = fopen(argv[2],"w");

        InfoFile infos = {0};


        char line[256];
        while(fgets(line,sizeof(line),sorgente)) {
            fputs(line,destinazione);
            conta_struct(&infos);
        }

        printf("\n\nNumero di copie avvenute: %d\n\n", infos.counter);

        fclose(sorgente);
        fclose(destinazione);
    }
    return 0;
}