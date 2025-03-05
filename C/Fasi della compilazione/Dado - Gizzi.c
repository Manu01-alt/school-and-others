#include <stdio.h>  // usato per la funzione printf 
#include <stdlib.h> // usato per le funzioni di rand e srand
#include <time.h>	// usato per inizializzare il seed con time(NULL)
int main() {

int numero;
int i;
int frequenze[7]={0};
int dado;
srand(time(NULL));

printf("Inserire il numero di lanci: ");
scanf("%d", &numero);

for (i=0;i<numero;i++) {
	dado=rand() % 6+1;
	frequenze[dado]++;
}
for (i=1;i<=6;i++) {
printf("\nLe frequenze del numero %d sono: %d",i,frequenze[i]);
}
return 0;
}	