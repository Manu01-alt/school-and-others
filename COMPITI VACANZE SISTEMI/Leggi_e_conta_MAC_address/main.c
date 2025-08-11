#include <stdio.h>
#include <stdlib.h>

int main()
{
    char line[19]; //Variable used to store the MAC address + terminator + newline
    size_t len = sizeof(line);
    int counter = 0; 

    FILE *file_handle = fopen("mac_list.txt","r");

    //While loop that reads the MAC addresses from the file and prints them
    while (fgets(line,len,file_handle) != 0) {
        printf("%s",line);
        counter++;
    }

    // Closes the file
    fclose(file_handle);
    printf("\nsono stati stampati %d MAC address", counter);
    printf("\n\nFile chiuso");
    return 0;
}
