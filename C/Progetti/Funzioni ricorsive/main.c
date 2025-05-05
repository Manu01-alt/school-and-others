#include <stdio.h>
#include <stdlib.h>
#include "recursive_lib.h"

int main()
{

    unsigned int n=10;

    printf("La somma dei numeri fino a  %u vale %u",n, recursive_sum(n) );
    return 0;
}
