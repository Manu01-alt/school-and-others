#ifndef MYLIB_H
#define MYLIB_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* ipStr; // IP rappressentato come stringa
    uint32_t ip; // IP rappressentato come intero
    uint32_t netmask; // Netmask associata all'IP
    char classe; // Classe dell'IP (A, B, C, D, E)
}ip_t;
//funzione per il parsing della riga di comando
void parse_cli(int argc, char *argv[]);
//funzione per generare n IP casuali
void generate_ip(int n, ip_t ip);
//funzione per stampare le informazioni dell'IP
void print_ip(ip_t ip);
#endif // MYLIB_H