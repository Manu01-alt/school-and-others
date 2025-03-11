//GIZZI MANUEL 3CINF 07/03/25
#include <stdio.h> // per printf e scanf
#include <math.h>  // per pow
#include <time.h>  // per clock

int main()
{
    int N, a = 1, b, c;
    int counter = 0;
    clock_t start, end;
    double cpu_time_used;

    printf("Inserisci il numero di terne pitagoriche da generare: ");
    scanf("%d", &N);

    printf("Le prime %d terne pitagoriche sono:\n", N);

    // Inizia a misurare il tempo
    start = clock();

    // ciclo che si ripete per N volte
    while (counter < N)
    {
        b = a;
        while (counter < N) // Rimuove il limite per b
        {
            c = b;
            while (counter < N) // Rimuove il limite per c
            {
                if (pow(a, 2) + pow(b, 2) == pow(c, 2))
                {
                    printf("%d %d %d\n", a, b, c);
                    counter++;
                    if (counter >= N)
                        break;
                }
                c++;
            }
            if (counter >= N)
                break;
            b++;
        }
        a++;
    }

    // Termina la misurazione del tempo
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo di esecuzione: %f secondi\n", cpu_time_used);

    return 0;
}
