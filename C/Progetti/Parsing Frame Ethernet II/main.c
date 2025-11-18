//GIZZI MANUEL 4CINF
/* CONSEGNA:
Leggere da tastiera un frame Ethernet II in esadecimale, verificarne la validità e popolare una struct con:

MAC destinazione (6 byte),
MAC sorgente (6 byte),
EtherType (2 byte, big-endian),
payload (0..1500 byte).

Stampare poi una vista formattata dei campi
*/
#include <stdio.h> // per printf e fgets
#include <stdlib.h> // per malloc e free
#include <string.h> // strlen e strcpy

//Creazione del frame
struct Frame
{
    char* destinazione; // stringa per MAC Address destinatatio
    char* sorgente; // stringa per MAC Address sorgente
    char* ethertype; // stringa per Ethertype
    char* payload; // stringa per Payload (esadecimale)
    char* payloadASCII; // stringa per Payload (ASCII)
    int payload_size; // int per la grandezza totale del payload
    int frameTotale; // int per la grandezza totale del frame
};

// funzione per inizializzazione dinamica del frame
void initFrame(struct Frame *f, const char *str)
{

    f->destinazione = malloc(18); // MAC address + : + \0
    f->sorgente = malloc(18);
    f->ethertype = malloc(7); // 6 caratteri + \0

    int len = strlen(str);
    f->payload_size = (len - 28) / 2; // lunghezza del frame - MAC address e ethertype, diviso 2 perchè rappresentato in esadecimale testuale
    f->frameTotale = (len) / 2; // lunghezza totale del frame diviso 2 perchè rappresentato in esadecimale testuale

    if (f->payload_size > 0)
    {
        f->payload = malloc(f->payload_size * 3 + 1); // lunghezza del payload * 3 (2 caratteri + spazio) + \0
        f->payloadASCII = malloc(f->payload_size + 1); // lunghezza del payload + \0
    }
    else // alternativa se il payload è uguale a 0
    {
        f->payload = malloc(1);
        f->payloadASCII = malloc(1);
        f->payload_size = 0;
    }

    //inizializzazione iniziale delle stringhe
    strcpy(f->destinazione,"");
    strcpy(f->sorgente, "");
    strcpy(f->ethertype, "");
    strcpy(f->payload,"");
    strcpy(f->payloadASCII,"");
}

//rilascio della memoria dinamica
void freeMemoryFrame(struct Frame *f)
{
    free(f->destinazione);
    free(f->sorgente);
    free(f->ethertype);
    free(f->payload);
    free(f->payloadASCII);
}

//conversione da esadecimale ad ascii
char hextoByte (char hex[2]) {
    char result = 0;
    for (int i = 0; i < 2; i++) {
        result <<=4; //nibble shiftato di 4 posti a sinistra
        if (hex[i] >= '0' && hex[i] <='9') {
            result |= hex[i] - '0'; //conversione dei numeri da carattere al loro valore numeri
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            result |= hex[i] - 'A' + 10; //conversione delle lettere da carattere al loro valore numerico
        }
    }
    return result;
}


int main()
{
    char str[1515]; //Payload massimo di 1500 byte + 2 MAC Address (6*2) byte + Ethertype (2) byte + \0
    printf("Inserisci frame in esadecimale (byte separati da spazi o contigui):");
    fgets(str,sizeof(str),stdin); //uso di fgets per non avere problemi con gli spazi in input


    int i= 0,j = 0;

    //rimozione degli spazi e conversione delle lettere minuscole in maiuscolo
    while(str[i]) {
        if (str[i] != 0x20 && str[i] != '\n' && str[i] != '\r')
        {
            if(str[i] >= 'a' && str[i] <= 'f')
            {
                str[i] &= 0xDF;
            }
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';

    //controllo della lunghezza del frame
    if(strlen(str) < 28)
    {
        printf("Frame non valido!\n");
        return 1;
    }

    //istanziazione del frame
    struct Frame f;
    initFrame(&f, str);

    //MAC DESTINATARIO
    j = 0;
    for(i = 0; i < 12; i++) {
        f.destinazione[j++] = str[i];
        if (i % 2 != 0 && i < 11)
            f.destinazione[j++] = ':';
    }
    f.destinazione[j] = '\0';

    //MAC SORGENTE
    j = 0;
    for(i = 12; i < 24; i++) {
        f.sorgente[j++] = str[i];
        if (i % 2 != 0 && i < 23)
            f.sorgente[j++] = ':';
    }
    f.sorgente[j] = '\0';

    //ETHERTYPE
    j = 0;
    f.ethertype[j++] = '0';
    f.ethertype[j++] = 'x';
    for(i=24; i < 28; i++) {
        f.ethertype[j++] = str[i];
    }
    f.ethertype[j] = '\0';

    //PAYLOAD HEX
    j = 0;
    for ( i = 28; i < strlen(str); i += 2) {
    f.payload[j++] = str[i];
    f.payload[j++] = str[i+1];
    f.payload[j++] = ' ';
    }
    f.payload[j] = '\0';

    //PAYLOAD ASCII
    j = 0;
    for(i = 28; i < strlen(str); i += 2) {
        char hex[2] = {str[i], str[i+1]};
        char byte = hextoByte(hex);

        if(byte >= 32 && byte <= 126) {
            f.payloadASCII[j++] = byte;
        }
        else {
            f.payloadASCII[j++] = '.';
        }
    }
    f.payloadASCII[j] = '\0';

    printf("=== FRAME ETHERNET DECODIFICATO ===");
    printf("\nDestinazione : %s", f.destinazione);
    printf("\nSorgente : %s", f.sorgente);
    printf("\nEtherType : %s", f.ethertype);
    printf("\nPayload size : %d", f.payload_size);
    printf("\n\nPayload esadecimale:");
    printf("\n %s",f.payload);
    printf("\n------------------------------------------");
    printf("\n\nPayload ASCII");
    printf("\n %s", f.payloadASCII);
    printf("\n------------------------------------------");
    printf("\n Frame totale: %d byte\n", f.frameTotale);


    freeMemoryFrame(&f);
    return 0;
}
