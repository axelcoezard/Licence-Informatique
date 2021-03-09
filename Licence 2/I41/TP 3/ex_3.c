#include <stdio.h>
#include <stdlib.h>

#include "ex_3.h"

int main() {
    uint n = syracuse(14);
    printf("Le plus petit n pour que u = 1: %i\n", n);
}

/**
 * \brief Détermine si n est pair ou impair.
 * \param n Un entier non-signé.
 * \return Renvoie n/2 si n est pair et 3n+1 sinon.
 */
uint PairOuImpair(uint n) {
    return n % 2 == 0 ? n / 2 : 3 * n + 1;
}

/**
 * \brief Détermine le plus petit n pour que la suite de 
 * syracyse soit égale à 1.
 * \param u0 Un entier non-signé, premier terme de la suite.
 * \return Renvoie le plus petit n pour que u_n = 1.
 */
uint syracuse(uint u0) {
    int u = u0, n = 0;
    while((u = PairOuImpair(u)) != 1)
        n++;
    return n + 1;    
}