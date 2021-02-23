#include <stdio.h>
#include <stdlib.h>

#include "ex_2.h"

int main() {
    tbool test_1 = CommencePar("Bonjour", "Bon");
    printf("Bonjour commence par Bon? %d\n", test_1);

    tbool test_2 = CommencePar("Bonjour", "Bonh");
    printf("Bonjour commence par Bonh? %d\n", test_2);


}

/**
 * \brief Donne la taille d'un mot.
 * \param mot Le mot.
 * \return La taille du mot.
 */
uint TailleMot(char * mot) {
    int taille = 0;
    while(mot[taille] != '\0')
        taille++;
    return taille;
}

/**
 * \brief Décide si une chaîne mot commence par une autre chaine deb.
 * \param mot La chaine mot.
 * \param deb Le chaine deb.
 * \return TRUE si mot commence par deb, FALSE sinon.
 */
tbool CommencePar(char * mot, char * deb) {
    uint taille_deb = TailleMot(deb);
    if (taille_deb > TailleMot(mot)) 
        return FALSE;

    for(int i = 0; i < taille_deb; i++)
        if (mot[i] != deb[i]) return FALSE;
    return TRUE;
}

tbool BienParenthesee(char * expr) {

}