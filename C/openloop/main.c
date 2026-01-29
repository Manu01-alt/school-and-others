//Gizzi Manuel 4CINF
#include <stdio.h>
#include <stdlib.h>

//Definisco un tipo di struttura per archiviare i file aperti
typedef struct{
    FILE *fp;           //puntatore al file
    unsigned int index; //indice del file
    int fd;             //file descriptor (numero intero associato al file dal sistema operativo)                   
} archive_files;


//Definisco una struttura per tenere traccia delle aperture dei file
struct OpenInfo {
    unsigned int successfullOpens; //numero di file aperti con successo
    unsigned int failedOpens;      //numero di tentativi falliti di apertura file
    archive_files *fileList;       //puntatore alla lista
    unsigned int fileListSize;     //dimensione della lista dei file aperti
};

int main() {
    struct OpenInfo openInfo = {0, 0, NULL, 0}; //inizializzo la struttura OpenInfo
    archive_files *files = malloc(1 * sizeof(archive_files)); //alloco memoria dinamica per la lista dei file aperti
    
    //ciclo infinito per l'apertura dei file
    while (1) {
        FILE *test = fopen("test.txt", "r"); //apertura del file in lettura
        
        if (test != NULL) {
            openInfo.fileList = files; //aggiorno il puntatore alla lista dei file aperti
            files[openInfo.successfullOpens].fp = test; //assegno il puntatore al file aperto
            files[openInfo.successfullOpens].index = openInfo.successfullOpens; //assegno l'indice del file
            files[openInfo.successfullOpens].fd = fileno(test); //assegno il file descriptor
            openInfo.successfullOpens++; //incremento il numero di file aperti con successo, usato anche come indice dell'array dinamico
            files = realloc(files, (openInfo.successfullOpens + 1) * sizeof(archive_files)); //rialloco memoria per la lista dei file aperti
        }
        else {
            openInfo.failedOpens++; //incremento il numero di tentativi falliti di apertura file
            openInfo.fileListSize = openInfo.successfullOpens * sizeof(archive_files); //calcolo la dimensione della lista dei file aperti
            perror("fopen"); //scrivo su stderr l'errore di apertura file
            break;
        }
    }
    
    //chiudo tutti i file aperti e libero la memoria allocata
    for (unsigned int i = 0; i < openInfo.successfullOpens; i++) {
        fclose(files[i].fp);
    }
    free(files);
    
    printf("REPORT FINALE:\n");
    printf("Aperture: %u\n", openInfo.successfullOpens);
    printf("Tentativi Falliti: %u\n", openInfo.failedOpens);
    printf("Dimensione lista: %u\n", openInfo.fileListSize);
    
    return 0;
}