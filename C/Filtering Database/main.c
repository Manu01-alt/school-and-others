#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htoi.inc" // funzione htoi()

typedef struct {
    int porta;
    unsigned char MACd[6];
    unsigned char MACs[6];
} TRAFFICO; 

TRAFFICO* pt0; 
TRAFFICO* pt;

typedef struct{
    int porta;
    unsigned char MAC[6];
    int age;
}FILTERINGDB; 

FILTERINGDB* pf0; 
FILTERINGDB* pf;

int FromMACtoByte(char *szmac, int offs, int idx);
int isMACequal(unsigned char *mac1, unsigned char *mac2);


int main(int argc, char* argv[]) {
    
    FILE *fp;
    int i, j, nT, nF;
    char szRiga[80];

    if (argc != 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        printf("Usage: %s file.txt\n", argv[0]);
        return 1;
    }

    printf("Traffico\n-----------------------------------------\n");
    i = 0;
    fp = fopen(argv[1], "r");
    fgets(szRiga, 80, fp); 
    printf("%s", szRiga);
    while(fgets(szRiga, 80, fp) != NULL){
        printf("%s", szRiga);
        if(szRiga[0]){
            if(i == 0) {pt0 = malloc(sizeof(TRAFFICO)); pt = pt0;}
            else {pt0 = realloc(pt0, (i+1)*sizeof(TRAFFICO)); pt = pt0 + i;}

            pt->porta = szRiga[0] - '0';
            for(j = 0; j < 6; j++){
                pt->MACd[j] = (unsigned char)FromMACtoByte(szRiga, 2, j);
                pt->MACs[j] = (unsigned char)FromMACtoByte(szRiga, 20, j);
            }
            i++;
            nT = i;
        }
    }   
    fclose(fp);

    printf("\nLearning e forwarding\n-----------------------------------------");
    nF = 0;
    for(i = 0; i < nT; i++){
        int found = 0;
        for(j = 0; j < nF; j++){
            if((pf0 + j)->porta == (pt0 + i)->porta){
                if((isMACequal((pf0 + j)->MAC, (pt0 + i)->MACs))){
                    found = 1;
                    break;
                }
            }
        }
        if(!found){
            if(nF == 0) {pf0 = malloc(sizeof(*pf0)); pf = pf0;}
            else {pf = realloc(pf0, (nF+1)*sizeof(*pf0)); pf = pf0 + nF;}
            nF++;

            pf->porta = (pt0 + i)->porta;
            memcpy(pf->MAC, (pt0 + i)->MACs, sizeof(pf->MAC));
        }

        found = 0;
        for(j = 0; j < nF; j++){
            if(isMACequal((pf0 + j)->MAC, (pt0 + i)->MACd)){
                printf("\nTrama ricevuta su %d -> broadcast su ", (pt0 + i)->porta);
                found = 1;
            }
        }
        if(!found){
            printf("\nTrama ricevuta su %d -> broadcast su", (pt0 + i)->porta);
            for(j = 1; j <= 9; j++){
                if(j != (pt0 + i)->porta) printf(" %d", j);
            }
        }

    }
    
    printf("\n\nFiltering database\n-----------------------------------------\n");
    for(i = 0; i < nF; i++){
        printf("Porta: %d - MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",
               (pf0 + i)->porta,
               (pf0 + i)->MAC[0], (pf0 + i)->MAC[1], (pf0 + i)->MAC[2],
               (pf0 + i)->MAC[3], (pf0 + i)->MAC[4], (pf0 + i)->MAC[5]);
    }
    free(pt0);
    free(pf0);
    return 0;
}

int FromMACtoByte(char *szmac, int offs, int idx){
    char szbyte[3];
    szbyte[0] = szmac[offs + idx * 3];
    szbyte[1] = szmac[offs + idx * 3 + 1];
    szbyte[2] = 0;
    return htoi(szbyte);
}

int isMACequal(unsigned char *mac1, unsigned char *mac2){
    int i = 0;
    for(i = 0; i <  6; i++){
        if(*mac1 != *mac2) return 0;
        mac1++; mac2++;
    }
    return 1;
}