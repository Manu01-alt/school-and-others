// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXB 200000
#define MAXN 200000

int B, M, N, i;
int A[MAXN];
int R[MAXB];

int main() {
    // uncomment the two following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &M));

    for (i = 0; i < N; ++i)
        assert(1 == scanf("%d", &A[i]));

    B = 0;


    // INSERT YOUR CODE HERE


    printf("%d\n", B);
    for (i = 0; i < B; ++i)
        printf("%d ", R[i]);
    printf("\n");

    return 0;
}
