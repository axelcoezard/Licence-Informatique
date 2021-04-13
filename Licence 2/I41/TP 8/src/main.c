#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main(int argc, char **argv)
{
    int n = 10;
    int valuesA[] = {1, 4, 6, 8, 9, 0, 2, 3, 5, 7};
    int *valuesB = malloc(n * sizeof(int));

    t_list listA = {n, valuesA};
    t_list listB = {n, valuesB};

    merge(listA, 0, 5, 10);
    // merge(listA, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", valuesA[i]);
    printf("\n");

    // for (int i = 0; i < n; i++)
    //     printf("%d ", valuesB[i]);
    // printf("\n");
}

void copy(t_list X, uint i, t_list Y, uint j, uint n)
{
    int k = 0;
    while (k < n)
    {
        Y.values[j + k] = X.values[i + k];
        k++;
    }
}

void merge(t_list L, uint p, uint q, uint r)
{
    int Gn = q - p, Dn = r - q;
    t_list G = {Gn, malloc(Gn * sizeof(int))};
    t_list D = {Dn, malloc(Dn * sizeof(int))};

    copy(L, p, G, 0, Gn);
    copy(L, q, D, 0, Dn);

    int i = 0, j = 0, k = p;
    while (i < Gn && j < Dn)
    {
        if (G.values[i] <= D.values[j])
            L.values[k] = G.values[i++];
        else
            L.values[k] = D.values[j++];
        k++;
    }

    free(G.values);
    free(D.values);
}

void MergeSort(t_list L, uint p, uint r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(L, p, q);
        MergeSort(L, q + 1, r);
        merge(L, p, q, r);
    }
}