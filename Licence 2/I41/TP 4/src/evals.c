#include <stdio.h>
#include <stdlib.h>

#include "evals.h"
#include "expos.h"

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
    int n = sizeof(P) - 2;
    printf("%f\n", n);
    while(i <= n) {
        // R ← R + P[i] * Exp(x,i)
        R += P[i] * Exp(a, i);
        i++;
    }
    return R;
}

float Eval_SM(float *P, float a) {
    float R = P[0];
    int i = 1;
    int n = sizeof(P) - 2;
    while(i <= n) {
        R += P[i] * SquareMultiply(a, i); // R ← R + P[i] * Exp(x,i)
        i++;
    }
    return R;
}

float Eval_Horner(float *P, float a) {
    float R = 0;
    int i = 0;
    int n = sizeof(P) - 2;
    while (i <= n) {
        R = R * a + P[n - 1];
        i++;
    }
    return R;
}