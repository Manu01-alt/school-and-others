#include "livello3_rete.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define HEADER "[TRAN]"
#define HEADER_LEN 6
#define MTU 20
#define ID "01"

char** livello4_send(const char* dati) {
    int len = strlen(dati);
    int offset = 0;
    int frammentazioni = (len + MTU - 1) / MTU;
    int frammento_index = 0;

    char** frammenti = malloc(sizeof(char*) * frammentazioni);

    printf("\nAndata Livello 4:\n");

    while (offset < len) {
        char payload[len + offset];
        strcpy(payload, dati + offset);
        payload[len+offset] = '\0';

        char header[64];
        sprintf(header, "%s[FRAG=%d/%d][ID=%s]", HEADER, frammento_index + 1, frammentazioni, ID);
        int totale_len = strlen(header) + strlen(payload) + 1;


        char* frammento = malloc(totale_len);
        sprintf(frammento, "%s%s", header, payload);

        frammenti[frammento_index++] = frammento;
        printf("%s\n", frammento);

        for (int i = 0; i < frammento_index; i++)
        {
            printf("Frammento %d: %s\n", i + 1, frammenti[i]);

        }

        //livello3_send(frammento);

        offset += MTU;
    }

    return frammenti;
}


char* livello4_receive(const char* dati)
{
    char* buffer=livello3_receive(dati);
    buffer=strstr(buffer, "]")+1;
    buffer=strstr(buffer, "]")+1;
    buffer=strstr(buffer, "]")+1;

    printf("\nRitorno Livello 4:\n%s", buffer);

    return (buffer);
}
