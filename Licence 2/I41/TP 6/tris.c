#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tris.h"

int main(int argc, char **argv)
{
    int L_size = atoi(argv[1]);
    int *L = generate_list(L_size, 100);
    show_list(L, L_size);

    TriSelection(L, L_size);
    show_list(L, L_size);
}

int *generate_list(int n, int max)
{
    int *list = malloc(n * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        list[i] = rand() % max;
    return list;
}

void show_list(int *L, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", L[i]);
    printf("\n");
}

int IdxMin(int *L, int a, int b)
{
    int i = a, min_i = a;
    while (i <= b)
    {
        if (L[i] < L[min_i])
            min_i = i;
        i++;
    }
    return min_i;
}

void TriSelection(int *T, int n)
{
    int ptr = 0;
    while (ptr < n)
    {
        int min_i = IdxMin(T, ptr, n);
        int tmp = T[ptr];
        T[ptr] = T[min_i];
        T[min_i] = tmp;
        ptr++;
    }
}

void TriBulles(int *L, int n)
{
}

void TriInsertion(int *T, int n)
{
}

ullong TrierTout(int n)
{
    return 0;
}
