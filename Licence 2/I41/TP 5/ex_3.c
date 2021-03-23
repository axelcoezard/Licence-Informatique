#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex_2.h"
#include "ex_3.h"

int main() {
    uint A[2] = {2, 5};
    uint B[3] = {3, 2, 6};

    uint *R =  Addition(A, 2, B, 3, 10);
    int size = 4;
    for(int i = 0; i < size; i++)
        printf("%d\n", R[i]);
}

uint *Addition(uint *A, uint size_A, uint *B, uint size_B, uint base) {
    if (B > A) {
        uint *tmp = A;
        A = B;
        B = tmp;
        int tmp_s = size_A;
        size_A = size_B; 
        size_B = tmp_s;
    }    
    uint *C = malloc((size_A + 1) * sizeof(uint));
    for (int i = 0; i < size_A + 1; i++)
        C[i] = 0;

    int i = 0, retenue = 0;
    while (i < size_B) {
        C[i] = A[i] + B[i] + retenue;
        if (C[i] >= base) {
            retenue = 1;
            C[i] -= base;
        } else retenue = 0;
        i++;
    }
    while (i < size_A) {
        C[i] = A[i] + retenue;
        if (C[i] >= base) {
            retenue = 1;
            C[i] -= base;
        }
        else retenue = 0;
        i++;
    }
    if (retenue > 0) C[i] = retenue;
    return C;
}