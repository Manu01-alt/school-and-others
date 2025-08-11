#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file_handle = fopen("IP_list.txt","w");
    char* ip = calloc(1,16);
    int counter = 0;

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

    FILE *file_handle2 = fopen("IP_list.txt","r");

    char line[18];
    size_t len = 18;

    while (fgets(line,len,file_handle2) != 0) {
        printf("%s",line);
    }

    fclose(file_handle2);
    printf("File chiuso");
    return 0;
}
