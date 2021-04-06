#include <stdio.h>
#include <stdlib.h>

#include "tri_tas.h"

int main(int argc, char **argv)
{
}

void Echanger(int *T, uint a, uint b)
{
    int tmp = T[a];
    T[a] = T[b];
    T[b] = tmp;
}

void Tamiser(int *T, uint i, uint n)
{
    uint child;
    if (child < n && T[child + 1] > T[child])
        child++;
    if (child <= n && T[i] < T[child])
    {
        Echanger(T, i, child);
        Tamiser(T, child, n);
    }
}