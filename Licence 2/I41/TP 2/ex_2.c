#include <stdio.h>
#include <stdlib.h>

#include "ex_2.h"

int main() {
    tbool test_1 = CommencePar("Bonjour", "Bon");
    printf("Bonjour commence par Bon? %d\n", test_1);

    tbool test_2 = CommencePar("Bonjour", "Bonh");
    printf("Bonjour commence par Bonh? %d\n", test_2);

    tbool test_3 = BienParenthesee("(3+2(5−1))");
    tbool test_4 = BienParenthesee("((2+3)(1−(1/2))−2)");
    tbool test_5 = BienParenthesee(")2(+(3−1)");

    printf("(3+2(5−1)) ? %d\n", test_3);
    printf("((2+3)(1−(1/2))−2) ? %d\n", test_4);
    printf(")2(+(3−1) ? %d\n", test_5);
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

/**
 * \brief Décide si une chaîne expr est une expression bien parenthésée.
 * \param expr La chaine à vérifier.
 * \return TRUE si la chaine est bien parenthésée, FALSE sinon.
 */
tbool BienParenthesee(char * expr) {
    uint taille_expr = TailleMot(expr);
    int count = 0;

    for(uint i = 0; i < taille_expr; i++) {
        if(expr[i] == '(') count++;
        if(expr[i] == ')') count--;
        if(count < 0) break;
    }
    return count == 0 ? TRUE : FALSE;
}