#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tris.h"

int main(int argc, char **argv)
{
    int L_size = atoi(argv[1]);

    // Test du tri Sélection
    int *L_1 = generate_list(L_size, 100);
    show_list(L_1, L_size);
    TriSelection(L_1, L_size);
    show_list(L_1, L_size);
    // Test du tri à Bulles
    int *L_2 = generate_list(L_size, 100);
    show_list(L_2, L_size);
    TriBulles(L_2, L_size);
    show_list(L_2, L_size);
    // Test du tri Insertion
    int *L_3 = generate_list(L_size, 100);
    show_list(L_3, L_size);
    TriInsertion(L_3, L_size);
    show_list(L_3, L_size);

    int *perms = generate_perms(L_size);
    show_list(perms, L_size);
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
 */
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

/**
 * \brief Effectue le Tri à Bulles d'une liste L
 * \param L Une liste d'entiers.
 * \param n La taille de la liste.
 */
void TriBulles(int *L, int n)
{
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
            }
            i++;
        }
        ptr++;
    }
}

/**
 * \brief Effectue le Tri Insertion d'une liste T
 * \param T Une liste d'entiers.
 * \param n La taille de la liste.
 */
void TriInsertion(int *T, int n)
{
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
        i++;
    }
}