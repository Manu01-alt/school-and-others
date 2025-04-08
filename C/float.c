#include <stdio.h>
#include <stdint.h>

void encodeFloat(float n)
{
    int s = -2 * ((unsigned int)n >> 31) + 1;
    int e = (((unsigned int)n >> 23) & 0xFF) - 127;
    unsigned int m = (unsigned int)n & 0x007FFFFF;

    printf("%d * 1.%u * 2^%d\n", s, m, e);
}

void encodeDouble(double n) {
    int s = -2 * ((unsigned long long)n >> 63) + 1;
    int e = (((unsigned long long)n >> 52) & 0x7FF) - 1023;
    unsigned long long m = (unsigned long long)n & 0x000FFFFFFFFFFFFF;

    printf("%d * 1.%llu * 2^%d\n", s, m, e);
}

void encodeHalf(uint16_t n)
{
    short s = -2 * ((unsigned short)n >> 15) + 1;
    short e = (((unsigned short)n >> 10) & 0x1F) - 15;
    unsigned short m = (unsigned short)n & 0x03FF;

    printf("%d * 1.%u * 2^%d\n", s, m, e);
}

void decodeFloat(float n) {
    int s = -2 * ((unsigned int)n >> 31) + 1;
    int e = (((unsigned int)n >> 23) & 0xFF) - 127;
    unsigned int m = (unsigned int)n & 0x007FFFFF;

    printf("Segno: %d\n",s);
	
	printf("Esponente: ");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (e >> i) & 0x1);
    }
    printf("\nMantissa: ");
    for (int i = 22; i >= 0; i--)
    {
        printf("%d", (m >> i) & 0x1);
    }
    printf("\n");
}

void decodeDouble(double n) {
    int s = -2 * ((unsigned long long)n >> 63) + 1;
    int e = (((unsigned long long)n >> 52) & 0x7FF) - 1023;
    unsigned long long m = (unsigned long long)n & 0x000FFFFFFFFFFFFF;

    printf("Segno: %d\n",s);
	
	printf("Esponente: ");
    for (int i = 10; i >= 0; i--)
    {
        printf("%d", (e >> i) & 0x1);
    }
    printf("\nMantissa: ");
    for (int i = 51; i >= 0; i--)
    {
        printf("%lld", (m >> i) & 0x1);
    }
    printf("\n");
}

void decodeHalf(uint16_t n) {
    short s = -2 * ((unsigned short)n >> 15) & 0x1;
    short e = (((unsigned short)n >> 10) & 0x1F) -15;
    short m = (unsigned short)n & 0x03FF;

    printf("Segno: %d\n",s);
	
	printf("Esponente: ");
    for (int i = 4; i >= 0; i--)
    {
        printf("%d", (e >> i) & 0x1);
    }
    printf("\nMantissa: ");
    for (int i = 9; i >= 0; i--)
    {
        printf("%d", (m >> i) & 0x1);
    }
}

int main()
{
    float number = 1.234;
    uint16_t half_number = 0x3C00;  // Numero in half precision (ad esempio, 1.0)

    printf("Float Encoding:\n");
    encodeFloat(number);
    decodeFloat(number);
    
    printf("\nDouble Encoding:\n");
    encodeDouble((double)number);
    decodeDouble((double)number);

    printf("\nHalf Encoding:\n");
    encodeHalf(half_number);
    decodeHalf(half_number);
    
    return 0;
}