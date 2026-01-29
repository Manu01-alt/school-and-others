#ifndef IPLIB_H_INCLUDED
#define IPLIB_H_INCLUDED
#include <stdint.h>

typedef struct{
    uint32_t ip;
    char class;
    uint32_t netMask;
} ip_t;

void generate_ip(ip_t *ip);
void determine_class(ip_t *ip);

#endif