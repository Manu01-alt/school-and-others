#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

import sys

# uncomment the two following lines if you want to read/write from files
sys.stdin = open('input1.txt')
sys.stdout = open('output1.txt', 'w')

N, M = map(int, input().strip().split())

A = list(map(int, input().strip().split()))

B = 0
R = [0 for i in range(B)]


# INSERT YOUR CODE HERE
A.sort()
max_dist = 0 

if(A[0] == A[N - 1]):
    B = 0
else:
    for i, c in enumerate(A):
        if abs(c[i] - c[i+1]) > max_dist:
            max_dist = abs(c[i] - c[i+1])

    if(M == 2):
        B = 1

    elif((M - 1) == max_dist):
        B = max_dist - 1
        for i in range(max_dist - 2):
                R.append(M - 1 -i)
    R.sort()
    R.append(0)



print(B)
for i in range(B):
    print(R[i], end=' ')
print()

sys.stdout.close()
