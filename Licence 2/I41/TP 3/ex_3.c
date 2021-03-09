#include <stdio.h>
#include <stdlib.h>

#include "ex_3.h"

int main() {
    // Calcul de la coubre des temps de vol de la suite
    // de Syracuse pour une précision choisie par
    // l'utilisateur.
    int precision;
    printf("Entrez la précision de vol: \n");
    scanf(" %d", &precision);

    FILE *file = fopen("./mongraphe.txt", "w+"); 
    if (file != NULL)
    {
        for(int i = 1; i <= precision; i++) {
            uint min_n = syracuse(i);
            fprintf(file, "%i %i\n", i, min_n);
        }
    }
    fclose(file);
    system("gnuplot -persist -e \"plot './mongraphe.txt' with lines linewidth 1.5\"");

    // Test de calcul du temps de vol et de l'altitude maximum
    // de la suite de Syracuse pour u0=4.563.281.
    int temps;
    int altitude;
    analyse(4563281, &temps, &altitude);
    printf("Altitude max: %d\n", altitude);
    printf("Temps de vol: %d\n", temps);
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
    int n = 0;
    while((u0 = PairOuImpair(u0)) != 1) n++;
    return n + 1;    
}

/**
 * \brief Détermine l'altitude maximum et le temps de vol
 de la sutie de Syracuse pour un u0 donné.
 * \param u0 Un entier non-signé, premier terme de la suite.
 * \param temps Un pointeur sur entier, correspondant au temps de vol.
 * \param altitude Un pointeur sur entier, correspondant a l'altitude max.
 */
void analyse(uint u0, int *temps, int *altitude) {
    *temps = 1;
    *altitude = u0;
    while((u0 = PairOuImpair(u0)) != 1) {
        if(u0 > *altitude) 
            *altitude = u0;
        (*temps)++;
    }
}