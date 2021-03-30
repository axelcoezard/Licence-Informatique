#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex_2.h"

int main()
{
    uint *inverse = S2L("320154");
    for (int i = 0; i < 6; i++)
        printf("%d\n", inverse[i]);

    char *reverse = L2S(inverse);
    printf("%s\n", reverse);
}

/**
 * \brief Renvoie le tableau des symboles transtypés en entiers qui constitue une chaine
 de caractères et dans l'ordre inverse.
 * \param chaine La chaine de caractère
 * \return Le tableau des symboles transtypés en entiers
 */
uint *S2L(char *chaine)
{
    int size = strlen(chaine);
    uint *inverse = malloc(size * sizeof(int));
    uint i = 0;
    while (i < size)
    {
        inverse[size - i - 1] = chaine[i] - '0';
        i++;
    }
    return inverse;
}

/**
 * \brief Transforme un tableau d'entiers en chaîne de caractères dans l'ordre inverse
 * \param liste La liste d'entiers.
 * \return Le tableau d'entiers en chaîne de caractères
 */
char *L2S(uint *liste)
{
    int size = sizeof(liste) - 2;
    char *reverse = malloc(size * sizeof(char));
    uint i = 0;
    while (i < size)
    {
        reverse[size - i - 1] = liste[i] + '0';
        i++;
    }
    return reverse;
}