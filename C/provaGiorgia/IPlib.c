#include "IPlib.h"
#include <stdlib.h>
#include <stdio.h>

void generate_ip(ip_t *ip){
    //generate the first octect random, based on the ip class
    switch (ip->class){
        case 'A': case 'a':
            ip->ip = rand() % 128;
            break;
        case 'B': case 'b':
            ip->ip = (rand() % 64) + 128;
            break;
        case 'C': case 'c':
            ip->ip = (rand() % 32) + 192;
            break;
        case 'D': case 'd':
            ip->ip = (rand() % 192) + 32;
            break;
        default:
            ip->ip = rand() % 256;
            break;
    }
    //generate the other 3 octects
    for(int i = 1; i < 4; i++){
        ip->ip = (ip->ip << 8) | (rand() % 256);
    }
}
void determine_class(ip_t *ip){
    if((ip->ip & 0x80000000) == 0){
        ip->class = 'A';
        ip->netMask = 0xFF000000;
    }
    else if((ip->ip & 0xC0000000) == 0x80000000){
        ip->class = 'B';
        ip->netMask = 0xFFFF0000;
    }
    else if((ip->ip & 0xE0000000) == 0xC0000000){
        ip->class = 'C';
        ip->netMask = 0xFFFFFF00;
    }
    else{
        ip->class = 'D';
        ip->netMask = 0;
    }
}