#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "evals.h"

float *Creer_Poly(uint n);

int main () {
    int taille;
    printf("Entrer le degrée du polynome: \n");
    scanf(" %d", &taille);

    float* poly = Creer_Poly(taille);

    float R_1 = Eval_Naif(poly, 3);
    float R_2 = Eval_SM(poly, 3);
    float R_3 = Eval_Horner(poly, 3);

    printf("%f %f %f\n", R_1, R_2, R_3);
}

float *Creer_Poly(uint n) {
    float *poly = malloc(
        (n + 1) * sizeof(float)
    );

    srand(time(NULL));
    for(int i = 0; i < n + 1; i++)
        poly[i] = rand() % 9 + 1;

    return poly;
}