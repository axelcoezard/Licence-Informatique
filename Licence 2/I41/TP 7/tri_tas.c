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
    uint child = 2 * i;
    if (child < n && T[child + 1] > T[child])
        child++;
    if (child <= n && T[i] < T[child])
    {
        Echanger(T, i, child);
        Tamiser(T, child, n);
    }
}

void Entasser(int *T, uint n)
{
    uint i = n / 2;
    while (i > 0)
    {
        Tamiser(T, i, n);
        i--;
    }
}

void TriTas(int *T, uint n)
{
    Entasser(T, n);
    uint k = n;
    while (k > 0)
    {
        Echanger(T, 1, k);
        Tamiser(T, 1, k - 1);
        k--;
    }
}

/**
 * \brief Génère une tableau contenant n entiers permutés.
 * \param n La taille du tableau et la valeur maximal de chaque entier.
 * \return un tableau d'entiers permutés.
 */
int *generate_perms(int n)
{
    int *perms = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        perms[i] = i + 1;

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int index = rand() % n;
        int tmp = perms[i];
        perms[i] = perms[index];
        perms[index] = tmp;
    }

    return perms;
}