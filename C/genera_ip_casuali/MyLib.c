#include "MyLib.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void parse_cli(int argc, char* argv[]) {
    ip_t ip;
    srand(time(NULL));
    // Valori di default
    int n = 1;
    
    // CASO 1: Nessun argomento
    if (argc == 1) {
        generate_ip(1, ip);
        return;
    }

    //Stampa dell'help
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        printf("Usage: %s [-nX] [-cY] [-iCIDR]\n", argv[0]);
        printf(" -nX : Generate X random IP addresses (default 1)\n");
        printf(" -cY : Specify class of IP addresses (A, B, C, D, E)\n");
        printf(" -iCIDR : Specify network in CIDR notation (e.g., 192.168.1.0/24)\n");
        return;
    }
    
    // Solo un argomento
    if (argc == 2) {
        char* arg1 = argv[1];
    if (strcmp(arg1, "-n")) {
        ip.classe = '?'; //classe non specificata
        ip.netmask = 0xFFFFFFFF; //netmask di default
        generate_ip(1, ip); //genera un IP casuale
    }
    else if (arg1[1] == 'n' && arg1[2] >= '0' && arg1[2] <= '9') {
        n = arg1[2] - '0';
        ip.classe = '?'; //classe non specificata
        ip.netmask = 0xFFFFFFFF; //netmask di default
        generate_ip(n, ip); //genera n IP casuali
    }
    else if (arg1[1] == 'c' && strchr("ABCDE", arg1[2])) {
       ip.classe = arg1[2]; //imposta la classe dell'IP
        generate_ip(1, ip); 
    }
    else if(arg1[1] == 'i') {
    
        char* cidr_str = &arg1[2];  // imposta il puntatore alla stringa CIDR
        
        uint32_t oct[4];
        int cidr_bits;
        
        // divisione della stringa CIDR in ottetti e bit di rete
        sscanf(cidr_str, "%u.%u.%u.%u/%d", &oct[0], &oct[1], &oct[2], &oct[3], &cidr_bits);
        
        // Calcolo della netmask a partire dal numero di bit di rete
        uint32_t netmask = 0xFFFFFFFF << (32 - cidr_bits);
        
        // Imposta la netmask nell'IP
        ip.netmask = netmask;
        generate_ip(1, ip); //genera un IP casuale nella rete specificata
 
    }
    else {
        fprintf(stderr, "Errore: Argomento non valido %s\n", arg1); //stampa dell'errore
        exit(1);
    }
    }
    
    // Due argomenti
    if (argc == 3) {
        char* arg1 = argv[1]; // primo argomento
        char* arg2 = argv[2]; // secondo argomento
        
        if (arg1[1] == 'n' && arg1[2] >= '0' && arg1[2] <= '9') {
            ip.classe = '?'; //classe non specificata
            ip.netmask = 0xFFFFFFFF; //netmask di default
            n = arg1[2] - '0';

            if (arg2[1] == 'c' && strchr("ABCDE", arg2[2])) {
                ip.classe = arg2[0];
                generate_ip(n, ip);
                
            } else if (arg2[1] == 'i') {
                char* cidr_str = &arg2[2];  
                
                uint32_t oct[4];
                int cidr_bits;
                
                sscanf(cidr_str, "%u.%u.%u.%u/%d", &oct[0], &oct[1], &oct[2], &oct[3], &cidr_bits);
                
                uint32_t netmask = 0xFFFFFFFF << (32 - cidr_bits);
                
                ip.netmask = netmask;

                generate_ip(n, ip);
            } else {
                fprintf(stderr, "Errore: Argomento non valido %s\n", arg2);
                exit(1);
            }
        }
    }

}

void generate_ip(int n, ip_t ip) {
    for (int i = 0; i < n; i++) {
    // genera n IP
        uint32_t random_ip = 0;
        
        // se è specificata una netmask inizializza l'IP di base
        if (ip.netmask != 0 && ip.netmask != 0xFFFFFFFF) {
            uint32_t host_mask = ~ip.netmask;
            uint32_t random_host = rand() & host_mask;
            random_ip = ip.ip | random_host; 
          // se è specificata una classe, inizializza il primo ottetto in base alla classe
        } else if (ip.classe == 'A' || ip.classe == 'B' || ip.classe == 'C' || ip.classe == 'D' || ip.classe == 'E') {
            uint8_t first_octet;
            
        switch (ip.classe) {
            case 'A':
                first_octet = rand() % 126 + 1;     // 1-126
                break;
            case 'B':
                first_octet = rand() % (191 - 128 + 1) + 128;   // 128-191
                break;
            case 'C':
                first_octet = rand() % (223 - 192 + 1) + 192;   // 192-223
                break;
            case 'D':
                first_octet = rand() % (239 - 224 + 1) + 224;   // 224-239
                break;
            case 'E':
                first_octet = rand() % (255 - 240 + 1) + 240;   // 240-255
                break;
            default:
                first_octet = rand() % 256;          // 0-255
                break;
        }

            // genera gli altri ottetti casualmente
            random_ip = ((uint32_t)first_octet << 24) |
                       ((uint32_t)(rand() % 256) << 16) |
                       ((uint32_t)(rand() % 256) << 8) |
                       ((uint32_t)(rand() % 256));
        }
        //genera un IP completamente casuale
        else {
            random_ip = ((uint32_t)(rand() % 256) << 24) |
                       ((uint32_t)(rand() % 256) << 16) |
                       ((uint32_t)(rand() % 256) << 8) |
                       ((uint32_t)(rand() % 256));
            ip.netmask = 0xFFFFFFFF; // netmask di default
            ip.classe = '?'; // classe non specificata
        }
        
        // assegna l'IP generato alla struttura
        ip.ip = random_ip;
        
        // converte l'IP in stringa
        ip.ipStr = (char*)malloc(16 * sizeof(char));
        sprintf(ip.ipStr, "%u.%u.%u.%u",
                (random_ip >> 24) & 0xFF,
                (random_ip >> 16) & 0xFF,
                (random_ip >> 8) & 0xFF,
                random_ip & 0xFF);
            
        
        
        // STAMPA
        print_ip(ip);
        
        // Libera memoria
        free(ip.ipStr);
    }
}


void print_ip(ip_t ip) {
    printf("IP: %s\n", ip.ipStr);
    printf("Intero: %u\n", ip.ip);
    printf("Netmask: %u\n", ip.netmask);
    printf("Classe: %c\n", ip.classe);
}   
