#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50

int main()
{
    int vet1[N],i,vet2[N]={0},k,vet3[N]={0};
    srand(time(NULL));

    for(i=0;i<N;i++)
    {
        vet1[i]=rand()%20+1;
        printf("%d\t",vet1[i]);

    }

        printf("\n\n");

    for(i=0;i<N;i++)
    {
        printf("%d\t",vet2[i]);

    }

    printf("\n\n");

    for(i=0;i<N;i++)
    {
        for(k=0;k<N; k++)
        {
            if(vet1[i]==vet2[k])
            {
                vet3[vet1[i]]++;
            }
        }
    }

    for(i=0;i<N;i++)
    {
        if(vet3[i]!=0)
        {
            printf("%d\t",vet3[i]);
        }

    }

    return 0;
}
