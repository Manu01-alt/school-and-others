#include <stdio.h>
#include <stdlib.h>
int main()
{
    int Ordine=0;
    int Matrice[Ordine][Ordine];
    int i,j;
    int det=0;

    //INSERIMENTO DELL'ORDINE DELLA MATRICE (compreso controllo dell'ordine)
    printf("\nInserire l'ordine della matrice tra 1 e 3: ");
    scanf("%d", &Ordine);

    while (Ordine>3) {
        printf("\nNumero troppo grande, inserire ordine compreso tra 1 e 3: ");
        scanf("%d", &Ordine);
    }


    //INSERIMENTO ELEMENTI NELLA MATRICE
    for (i = 0; i <Ordine; i++)
        {
            for (j = 0; j <Ordine; j++)
            {
                printf("Elemento riga[%d] colonna[%d] : ", i+1, j+1);
                scanf("%d", &Matrice[i][j]);
            }
        }

    //STAMPA DELLA MATRICE
    printf("\nLa matrice e':\n");
        for (i = 0; i < Ordine; i++)
        {
            for (j = 0; j < Ordine; j++)
            {
                printf("%5d\t", Matrice[i][j]);
            }
            printf("\n");
        }


//CALCOLO DEL DETERMINANTE

    if (Ordine==1) {
        det=Matrice[0][0];
    }
    else if (Ordine==2) {
        det = (Matrice[0][0]*Matrice[1][1]) - (Matrice[0][1]*Matrice[1][0]);
    }
    else if (Ordine==3) {
        det = (Matrice[0][0] * Matrice[1][1] * Matrice[2][2] + Matrice[0][1] * Matrice[1][2] * Matrice[2][0] + Matrice[0][2] * Matrice[1][0] * Matrice[2][1] ) -
            (Matrice[0][2] * Matrice[1][1] * Matrice[2][0] + Matrice[0][0] * Matrice[1][2] * Matrice[2][1] + Matrice[0][1] * Matrice[1][0] * Matrice[2][2]);
}

printf("\nIl determinante della Matrice e': %d", det);
    return 0;
}
