#include <stdio.h>
#include <stdlib.h>

#include "ex_1.h"

int main() {
    printf("Eval_Naif( = %i\n", Exp(2, 4));
}

/**
 * \brief Calcule la puissance i d'un nombre x.
 * \param x Un réel
 * \param i Un nombre réel, l'exposant.
 * \return x puissance i.
 */
int Exp(int x, int i) {
    int j = 0, r = 1;
    while (j < i) {
        r *= x;
        j++;
    }
    return r;
}

/**
 * \brief Calcule la valeur de la fonction polynomiale P en a de
 manière directe en utilisant l'algorithme d'exponentiation naïf.
 * \param P Une liste de n + 1 réels
 * \param a Un réel
 * \return La valeur de la fonction polynomiale P en a.
 */
float Eval_Naif(float *P, float a) {
    float R = P[0];
    int i = 1;
    while(i <= sizeof(P)) {
        R += P[i] * Exp(a, i); // R ← R + P[i] * Exp(x,i)
        i++;
    }
    return R;
}

float Eval_SM(float *P, float a) {
    
}