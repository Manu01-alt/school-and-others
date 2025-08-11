#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file_handle = fopen("ARP_table.txt","a");
    char* ip = calloc(1,16);
    char* mac = calloc(1,18);
    int stop = 1;

    do{
        printf("Inserire indirizzo IP o digitare 'fine': ");
        scanf("%s",ip);
        if (strcmp(ip,"fine") != 0) {
            printf("Inserire indirizzo MAC: ");
            scanf("%s",mac);
            fprintf(file_handle,"IP = %s MAC = %s\n",ip,mac);
        }
        else {
            stop = 0;
        }
    }

    while (stop == 1);
    fclose(file_handle);

    printf("IP salvati sul file di testo: \n");

    FILE *file_handle2 = fopen("ARP_table.txt","r");

    char line[50];
    size_t len = sizeof(line);

    printf("\n\nTABELLA:\n");
    while (fgets(line,len,file_handle2) != 0) {
        printf("%s",line);
    }

    fclose(file_handle2);
    printf("File chiuso");
    return 0;
}
