//GIZZI MANUEL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Opens the file for writing
    FILE *file_handle = fopen("IP_list.txt","w");
    char* ip = calloc(1,16);
    int counter = 0;

    // do while loop that takes the IP addresses wrote by the user in input and saves them on the file
    // it also counts the number of IP addresses saved
    do{
        printf("Inserire indirizzo IP: ");
        scanf("%s", ip);

        if (strcmp(ip,"fine") != 0) {
            fprintf(file_handle,"%s\n",ip);
            counter++;
        }
    }
    while (strcmp(ip,"fine") != 0);
    fclose(file_handle);

    printf("IP salvati sul file di testo: \n");

    // Opens the file for reading
    FILE *file_handle2 = fopen("IP_list.txt","r");

    char line[18]; // Variable used to store the IP address + terminator + newline
    size_t len = sizeof(line);

    // Reads the IP addresses from the file and prints them
    while (fgets(line,len,file_handle2) != 0) {
        printf("%s",line);
    }

    // Closes the file
    fclose(file_handle2);
    printf("File chiuso");
    return 0;
}
