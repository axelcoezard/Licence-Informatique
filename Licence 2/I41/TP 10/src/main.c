#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main(int argc, char **argv)
{
    uint L[6] = {1, 6, 5, 2, 7, 3};
    t_list list;
    list.n = 6;
    list.values = L;

    uint min = L[0];
    uint max = L[5];
    minMax(list, &min, &max);
    printf("Min: %d | Max: %d\n", min, max);

    LinearSort(list);

    printf("Sorted? %d\n", sorted(&list));

    t_cell chain = {5, NULL};
    chain = *Enfiler(&chain, 8);

    printf("Valeur: %d\n", chain.next);
    while (chain.next != NULL)
    {
        chain = *(chain.next);
    }
}

void minMax(t_list L, uint *min, uint *max)
{
    uint i;
    uint c;

    while (i < L.n)
    {
        c = L.values[i];
        if (c > *max)
            *max = c;
        else if (c < *min)
            *min = c;
        i++;
    }
}

t_list histogram(t_list L)
{
    t_list histogram;
    uint i;
    uint delta;
    uint min;
    uint max;

    min = L.values[0];
    max = L.values[L.n - 1];
    minMax(L, &min, &max);
    histogram.n = L.n;
    histogram.values = (uint *)malloc((max - min + 1) * sizeof(uint));
    delta = 1 - min;
    i = 0;
    while (i < L.n)
    {
        histogram.values[L.values[i++] + delta]++;
    }
}

void LinearSort(t_list L)
{
    uint i;
    uint j;
    uint min;
    uint max;
    uint delta;
    uint *H;

    min = L.values[0];
    max = L.values[L.n - 1];
    minMax(L, &min, &max);
    H = (uint *)malloc((max - min + 1) * sizeof(uint));
    delta = 1 - min;
    i = 0;
    while (i < L.n)
    {
        H[L.values[i++] + delta]++;
    }
    i = 0;
    j = 0;
    while (i < L.n)
    {
        if (H[j] > 0)
        {
            L.values[i] = j - delta;
            H[j]--;
            i++;
        }
        else
            j++;
    }
}

t_bool sorted(t_list *L)
{
    uint i;

    i = 0;
    while (i < L->n - 1)
    {
        if (L->values[i] > L->values[i + 1])
            return FALSE;
        i++;
    }
    return TRUE;
}

t_listc Enfiler(t_listc L, int value)
{
    struct t_cell cell = *L;
    struct t_cell new_cell;
    while (cell.next != NULL)
    {
        cell = *(cell.next);
    }
    new_cell.next = NULL;
    new_cell.value = value;
    cell.next = &new_cell;

    return L;
}

t_listc Empiler(t_listc L, int value)
{
}

t_listc Eteter(t_listc *L)
{
}

t_listc Repartir(t_listc L)
{
}

void TriRepartition(t_listc L)
{
}