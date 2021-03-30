#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tris.h"

int main(int argc, char **argv)
{
    int L_size = atoi(argv[1]);

    int start = time(NULL);
    int countdown;
    ullong K_1 = 0, K_2 = 0, K_3 = 0;
    while ((countdown = time(NULL) - start) < 60)
    {
        int *perms_1 = generate_perms(L_size);
        int *perms_2 = perms_1;
        int *perms_3 = perms_1;

        K_1 += TriSelection(perms_1, L_size - 1);
        K_2 += TriBulles(perms_2, L_size);
        K_3 += TriInsertion(perms_3, L_size);
    }

    printf("Nombres de permutations triées en 60s: %lld %lld %lld\n", K_1, K_2, K_3);
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

/**
 * \brief Génère une liste de n entiers aléatoires.
 * \param n La taille du tableau.
 * \param max La valeur maximal de chaque entier.
 * \return Une liste d'entiers.
 */
int *generate_list(int n, int max)
{
    int *list = malloc(n * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        list[i] = rand() % max;
    return list;
}

/**
 * \brief Affiche une liste L dans le terminal pour le débug.
 * \param L Une liste
 * \param n La taille de la liste
 */
void show_list(int *L, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", L[i]);
    printf("\n");
}

/**
 * \brief Renvoie l'indice du plus petit élement d'une sous-liste de L.
 * \param L Une liste d'entiers.
 * \param a Borne inférieur de la sous-liste.
 * \param b Borne supérieur de la sous-liste.
 * \return L'indice du plus petit élement.
 */
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

/**
 * \brief Effectue le Tri sélection d'une liste T
 * \param T Une liste d'entiers.
 * \param n La taille de la liste.
 * \return Nombre de comparaisons
 */
int TriSelection(int *T, int n)
{
    int K = 0;

    int ptr = 0;
    while (ptr < n)
    {
        K += n - ptr + 1;
        int min_i = IdxMin(T, ptr, n);
        int tmp = T[ptr];
        T[ptr] = T[min_i];
        T[min_i] = tmp;
        ptr++;
    }

    return K + ptr;
}

/**
 * \brief Effectue le Tri à Bulles d'une liste L
 * \param L Une liste d'entiers.
 * \param n La taille de la liste.
 */
int TriBulles(int *L, int n)
{
    int K = 0;

    int ptr = 0;
    while (ptr < n)
    {
        int i = 0;
        while (i < n - ptr - 1)
        {
            if (L[i + 1] < L[i])
            {
                int tmp = L[i];
                L[i] = L[i + 1];
                L[i + 1] = tmp;
                K++;
            }
            i++;
        }
        K += i;
        ptr++;
    }

    return K + ptr;
}

/**
 * \brief Effectue le Tri Insertion d'une liste T
 * \param T Une liste d'entiers.
 * \param n La taille de la liste.
 */
int TriInsertion(int *T, int n)
{
    int K = 0;

    int i = 0;
    while (i < n)
    {
        int j = i, current = T[i];
        while (j > 0 && T[j - 1] > current)
        {
            T[j] = T[j - 1];
            j--;
        }
        T[j] = current;
        K += j - i + 1;
        i++;
    }

    return K + i;
}