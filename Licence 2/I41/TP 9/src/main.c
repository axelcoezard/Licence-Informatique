#include <stdlib.h>
#include <stdlib.h>

#include "main.h"

int main(int argc, char **argv)
{
    t_list L;

    L.n = 4;
    L.values = malloc(sizeof(uint) * 4);
    L.values[0] = 5;
    L.values[1] = 1;
    L.values[2] = 3;
    L.values[3] = 8;

    QuickSort(&L, 0, L.n - 1);
    printf("Sorted? %d\n", sorted(&L));
}

void swap(t_list *L, uint i, uint j)
{
    uint tmp;

    tmp = L->values[i];
    L->values[i] = L->values[j];
    L->values[j] = tmp;
}

uint partition(t_list *L, uint p, uint r)
{
    uint i;
    uint j;
    uint x;

    x = L->values[p];
    i = p;
    j = r;
    while (L->values[j] > x)
    {
        j--;
    }
    while (i < j)
    {
        swap(L, i, j);
        do
        {
            j--;
        } while (L->values[j] > x);
        do
        {
            i++;
        } while (L->values[i] < x);
    }
    return (j);
}

void QuickSort(t_list *L, uint p, uint r)
{
    uint q;

    if (p < r)
    {
        q = partition(L, p, r);
        QuickSort(L, p, q);
        QuickSort(L, q + 1, r);
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