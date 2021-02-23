#include <stdio.h>
#include <stdlib.h>

#include "ex_1.h"

void main() {
    unsigned char n = 3;
    unsigned char b = 10;
    uint A[3] = {9, 9, 9};

    uint i = Increment(A, n, b);

    uint total = test(3, 10);

    printf("%i\n", i);
}

/**
 * \brief Incrémente un nombre A en base b de 1.
 * \param A Liste d'entiers non-signés.
 * \param n Taille de la liste.
 * \param b Base de la liste.
 * \return Le nombre de chiffres modifiés pour incrémenter de 1.
 */
uint Increment(uint * A, unsigned char n, unsigned char b) {
    uint retenu = 1; // Toujours égale à 0 ou 1.
    uint i = 0;      // Compteur de modifications.
    do {
        if(A[i] + retenu >= b) {
            A[i] = 0;
            retenu =  1;
        } else {
            A[i] += retenu;
            retenu = 0;
        }
        i++;
    } while (i < n && retenu > 0);
    return i;
}

/**
 * \brief Calcule le nombre total de modifications pour toutes les listes de taille n en base b.
 * \param n Taille des listes.
 * \param b Base des listes.
 * \return Nombre total de modifications pour toutes les listes.
 */
uint test(unsigned char n, unsigned char b) {
    uint * A = malloc(sizeof(uint) * n);
    uint possibilities = 1;
    for(int i = 0; i < n; i++) {
        possibilities *= b;
        A[i] = 0;
    }

    uint modifications = 0;
    for(int i = 0; i < possibilities; i++)
        modifications += Increment(A, n, b);

    printf("%i\n", modifications);
}
