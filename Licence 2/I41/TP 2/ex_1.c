#include <stdio.h>
#include <stdlib.h>

#include "ex_1.h"

int main() {
    uint A[3] = {9, 9, 9};
    uint i = Increment(A, 3, 10);

    unsigned char n = 8;
    unsigned char b = 10;
    uint modifs = test(n, b);

    printf("Incrément: %i\n", i);
    printf("Modifs totales: %i\n", modifs);
}

/**
 * \brief Incrémente un nombre A en base b de 1.
 * \param A Liste d'entiers non-signés.
 * \param n Taille de la liste.
 * \param b Base de la liste.
 * \return Le nombre de chiffres modifiés pour incrémenter de 1.
 */
uint Increment(uint * A, unsigned char n, unsigned char b) {
    uint i = 0, modifs = 0;
    while(i < n && A[i] == b - 1) {
        A[i] = 0;
        i++;
    }
    if(i < n) A[i]++;
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

    free(A);

    return modifications;
}
