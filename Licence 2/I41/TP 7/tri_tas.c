#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "tri_tas.h"

int main(int argc, char **argv)
{
    // Récupère dans argv la taille n du tableau.
    int n = atoi(argv[1]);
    // Récupère dans argv la durée requise pour l'évaluation.
    int length = atoi(argv[2]);
    //
    int *eval_tri = malloc(length * sizeof(int));
    int *eval_log = malloc(length * sizeof(int));
    //
    FILE *file_1 = fopen("./graph_eval.txt", "w+");
    FILE *file_2 = fopen("./graph_log.txt", "w+");
    //
    if (file_1 != NULL && file_2 != NULL)
    {
        int i = 0;
        while (i < length)
        {
            // Génère une tableau de taille n, de permutations aléatoires.
            int *perms = generate_perms(i);
            int coeff = 7;
            int eval_tri = TriTas(perms, i) / coeff;
            // Ecriture dans le fichier
            fprintf(file_1, "%d %d\n", i, eval_tri);
            fprintf(file_2, "%d %f\n", i, i * log10(i));
            i++;
        }
        fclose(file_1);
        fclose(file_2);
    }

    system("gnuplot -persist -e \"plot './graph_eval.txt' with lines linewidth 1.5, './graph_log.txt' with lines linewidth 1.5\"");
}

void Echanger(int *T, uint a, uint b)
{
    int tmp = T[a];
    T[a] = T[b];
    T[b] = tmp;
}

int Tamiser(int *T, uint i, uint n)
{
    int C = 2;
    uint child = 2 * i;
    if (child < n && T[child + 1] > T[child])
        child++;
    if (child <= n && T[i] < T[child])
    {
        Echanger(T, i, child);
        C += Tamiser(T, child, n);
    }
    return C;
}

int Entasser(int *T, uint n)
{
    uint i = n / 2;
    int C = i;
    while (i > 0)
    {
        C += Tamiser(T, i, n);
        i--;
    }
    return C;
}

int TriTas(int *T, uint n)
{
    uint k = n - 1;
    int C = Entasser(T, n) + k;
    while (k > 0)
    {
        Echanger(T, 0, k - 1);
        C += Tamiser(T, 0, k - 2);
        k--;
    }
    return C;
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

    struct timespec spec;
    clock_gettime(0, &spec);
    srand(spec.tv_nsec);
    for (int i = 0; i < n; i++)
    {
        int index = rand() % n;
        int tmp = perms[i];
        perms[i] = perms[index];
        perms[index] = tmp;
    }

    return perms;
}