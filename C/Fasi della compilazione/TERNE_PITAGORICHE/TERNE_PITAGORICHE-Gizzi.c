//GIZZI MANUEL 3CINF 07/03/25
#include <stdio.h> //per printf e scanf

int main()
{
    int N, a = 1, b, c;
    int counter = 0;

    printf("Inserisci il numero di terne pitagoriche da generare: ");
    scanf("%d", &N);

    printf("Le prime %d terne pitagoriche sono:\n", N);

    //ciclo che si ripete per N volte
    while (counter < N)
    {
        //limitiamo b in modo da evitare troppi cicli
        b = a;
        while (b <= 2 * a)
        {
            //limitiamo c in modo da evitare troppi cicli
            c = b;
            while (c <= 2 * b)
            {
                //controllo se e' una terna pitagorica, in caso la condizione si verifica la stampo
                if ((a * a) + (b * b) == (c * c))
                {
                    printf("%d %d %d\n", a, b, c);
                    counter++; //procedo ad incrementare i valori del counter, di a,b e c
                }
                c++;
            }
            b++;
        }
        a++;
    }

    return 0;
}
