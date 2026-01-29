#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "IPlib.h"

int main(int argc, char* argv[]){

    srand(time(NULL)); //initialize the timer
    
    FILE *outp = stdout;     //output file pointer
    int num = 1;    //default number of ips to generate
    char class;

    if(argc >= 2){
        //option -h for help
        if(!(strcmp(*(++argv), "-h"))){
            printf("raindip [-o OUTPUT] [-n NUM] [-c CLASS] [-h]");
            return 1;
        }
        else argv--; //move back the pointer

        //first option --> -o = file output
        if(!(strcmp(*(++argv), "-o"))){
            if((outp = fopen(*(++argv), "w")) == NULL){
                perror("error in the file opening!");
                return 1;
            }
        }
        else argv--; //move back the pointer

        if (argc == 4 || argc == 6) {
            if(!(strcmp(*(++argv), "-n"))) num = atoi(*(++argv));
        else argv--; //move back the pointer
        //-c --> specify the IP class
        if (argc == 6)
            if(!(strcmp(*(++argv), "-c"))) class = *(*(++argv));

    }else outp = stdout; //default output file pointer
    
    ip_t *ips = malloc(sizeof(ip_t) * num);

    for(int i = 0; i < num; i++){
        //generate IPs and determinate each class and netMask
        ips->class = class;
        generate_ip(ips);
        determine_class(ips);

        //print the results
        fprintf(outp, "\n******IP n.%d******", i + 1);
        fprintf(outp, "\n\tip --> %u.%u.%u.%u",(ips->ip >> 24) & 0xFF,
                      (ips->ip >> 16) & 0xFF,(ips->ip >> 8) & 0xFF,
                       ips->ip & 0xFF);
        fprintf(outp, "\n\tclass --> %c", ips->class);
        fprintf(outp, "\n\tnetID --> %u.%u.%u.%u\n",((ips->ip >> 24) & 0xFF) & ((ips->netMask >> 24) & 0xFF),
                      ((ips->ip >> 16) & 0xFF) & ((ips->netMask >> 16) & 0xFF), ((ips->ip >> 8) & 0xFF) & ((ips->netMask >> 8) & 0xFF),
                       (ips->ip & 0xFF) & (ips->netMask & 0xFF));
        
        ips++;  //move to the next ip
    }
    free(ips); //free the allocated memory
    if (outp != stdout) fclose(outp); //close the output file

    return 0;
}