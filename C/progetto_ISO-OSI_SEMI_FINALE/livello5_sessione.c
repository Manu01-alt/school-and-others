#include "livello4_trasporto.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int SESSIONE_ID=0;

char* livello5_send(const char* dati, const char action){
    char buffer[2048];
    SESSIONE_ID=rand() % 90000 + 10000;
    sprintf(buffer, "[SESS][ID=%d]%s", SESSIONE_ID, dati );
    printf("\nAndata Livello 5:\n%s",buffer);
    return livello4_send(buffer);
}

char* livello5_receive(const char* dati, const char action)
{
    char* buffer=livello4_receive(dati);

    buffer=strstr(buffer, "]")+1;

    const char* start = strstr(buffer, "[ID=");
    start += strlen("[ID=");
    int session_id = 0;
    sscanf(start, "%d", &session_id);

    if (session_id == SESSIONE_ID)
    {
        buffer=strstr(buffer, "]")+1;

        printf("\n\nRitorno Livello 2:\n%s", buffer);
        return buffer;
    }
    else
    {
        printf("\n\nErrore nella comunicazione nel livello 5: ID non corrispondente.");
        return NULL;
    }

    printf("\nRitorno Livello 5:\n%s", buffer);
    return buffer;
}
