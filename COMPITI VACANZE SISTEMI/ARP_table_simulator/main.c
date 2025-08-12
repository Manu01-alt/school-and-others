//GIZZI MANUEL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file_handle = fopen("ARP_table.txt","a");
    char* ip = calloc(1,16); // Variable used to store the IP address
    char* mac = calloc(1,18); // Variable used to store the MAC address
    int stop = 1;

    // do while loop that takes the IP and MAC addresses and saves them to the file
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

    char line[50]; // Variable used to store the ARP table entry + terminator + newline
    size_t len = sizeof(line);

    // Prints the ARP table
    printf("\n\nTABELLA:\n");
    while (fgets(line,len,file_handle2) != 0) {
        printf("%s",line);
    }

    // Closes the file
    fclose(file_handle2);
    printf("File chiuso");
    return 0;
}
