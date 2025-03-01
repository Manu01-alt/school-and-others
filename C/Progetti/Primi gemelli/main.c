#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrimo(int n){
    int i;

	if (n>=1 && n<=3) {
		return 1;
	}

	if (n % 2 == 0)
		return 0;

	for(i=3; i <= (int)sqrt(n); i += 2)
		if (n % i == 0)
			return 0;

	return 1;

}

int Primigemelli(int x, int y) {

    int controllo;

    if (isPrimo(x)==1 && isPrimo(y)==1){

    if (x-y==2 || x-y==-2) {

        controllo = 1;
    }
    else {
        controllo = 0;
    }
}

    return controllo;

}



int main() {

	int num1,num2, risultato;

	printf("Inserisci numero: ");
	scanf("%d", &num1);

	risultato = isPrimo(num1);

	if (risultato==1) {
		printf("\nIl numero e' primo\n");
	}
	else {
		printf("\nIl numero non e' primo\n");

	}

    printf("\nInserisci secondo numero: ");
	scanf("%d", &num2);

	risultato = isPrimo(num2);

	if (risultato) {
		printf("\nIl numero e' primo\n");
	}
	else {
		printf("\nIl numero non e' primo\n");

	}

	risultato = Primigemelli(num1,num2);

	if (risultato==1) {
        printf("\ni numeri sono primi gemelli\n");
	}
	else {
        printf("\ni numeri non sono primi gemelli\n");
	}

	return 0;
}
