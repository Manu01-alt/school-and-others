#include <stdio.h>
#include <stdlib.h>

int main()
{
    char line[19];
    size_t len = 19;
    int counter = 0;

    FILE *file_handle = fopen("mac_list.txt","r");

    while (fgets(line,len,file_handle) != 0) {
        printf("%s",line);
        counter++;
    }

    fclose(file_handle);
    printf("\nsono stati stampati %d MAC address", counter);
    printf("\n\nFile chiuso");
    return 0;
}
