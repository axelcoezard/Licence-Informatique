#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BASE_MAX 29

int **gen_cle_hill(int n);

int *Hill_affine_chiffre(char *texte, int **cle, int n);

char *Hill_affine_chiffre_en_chaine(char *texte, int **cle, int n);

int *Hill_affine_dechiffre(char *texte, int **cle, int n);

char *Hill_affine_dechiffre_en_chaine(char *texte, int **cle, int n);

int main(int argc, char **argv)
{
    // On génère une clef aléatoire
    int **cle = gen_cle_hill(3);
    // Un texte à chiffrer
    char *texte = "tes";
    // On chiffre le texte avec la clef de taille n.
    char *chiffre = Hill_affine_chiffre_en_chaine(texte, cle, 3);
    // Affichage du chiffré.
    for (int i = 0; i < 3; i++)
        printf("%c\n", chiffre[i]);
    /*
     * TO-DO: Déchiffrer le chiffré.
     */
}

/**
 * \brief Exercice 1
 *
    On a différentes équations à résoudres pour
    trouver la matrice:

    * avec 'baa' chiffré en 'hlt' on a:
        (x1 * 1 + 0 * y1 + z1 * 0) % 29 = 7 <=> x1 = 7
        (x2 * 1 + 0 * y2 + z2 * 0) % 29 = 11 <=> x2 = 11
        (x3 * 1 + 0 * y3 + z3 * 0) % 29 = 19 <=> x3 = 19

    * avec 'aba' chiffré en 'gdf' on a:
        (x1 * 0 + 1 * y1 + z1 * 0) % 29 = 6 <=> y1 = 6
        (x2 * 0 + 1 * y2 + z2 * 0) % 29 = 6 <=> y2 = 3
        (x3 * 0 + 1 * y3 + z3 * 0) % 29 = 6 <=> y3 = 5

    * et avec 'aab' chiffré en 'mcb' on a:
        (x1 * 0 + 0 * y1 + z1 * 1) % 29 = 12 <=> z1 = 12
        (x2 * 0 + 0 * y2 + z2 * 1) % 29 = 2 <=> z2 = 2
        (x3 * 0 + 0 * y3 + z3 * 1) % 29 = 1 <=> z3 = 1

    On obtient donc la matrice : (
        (7,6,12),
        (11,3,2),
        (19,2,1)
    )

    Qui nous permet de déchiffre le text et d'obtenir:
    TOUSLESDIXMETRESUNEPANCARTEINDIQUAITQUECEGRILLAGE
    ETAITELECTRIFIEUNPETITCHEMINLONGEAITLESGRILLAGES
    DECHAQUECOTEETLONPOUVAITYVOIRDETEMPSENTEMPSDEUX
    GARDESARMESFAIRELEURRONDELAROUTESEMBLAITINTERMINABLE
    CAILLOUTEUSEASOUHAITAUDELADESGRILLAGESCETAITLA
    FORETUNEFORETBIENENTRETENUEPRESQUEARTIFICIELLEPENSADAVIDZZ
 */

/**
 * \brief Exercice 2
 * 
 * Génère une matrice aléatoire inversible de taile n*n.
 */
int **gen_cle_hill(int n)
{
    struct timespec spec;
    int i;
    int j;
    int **cle;

    cle = malloc((n + 1) * sizeof(int *));
    i = 0;
    while (i < n + 1)
    {
        cle[i] = malloc(n * sizeof(int));

        clock_gettime(0, &spec);
        srand(spec.tv_nsec);
        j = 0;
        while (j < n)
        {
            cle[i][j] = rand() % BASE_MAX;
            j++;
        }
        i++;
    }
    return cle;
}

/**
 * \brief Exercice 3
 * 
 * Converti une chaine de caractère en un chiffré sous la forme
 * d'un tableau d'entiers modulo 29.
 */
int *Hill_affine_chiffre(char *texte, int **cle, int n)
{
    int i;
    int j;
    int c;
    int *caracteres;

    caracteres = malloc(n * sizeof(int));
    i = 0;
    while (i < n)
    {
        c = 0;
        j = 0;
        while (j < n)
        {
            c += cle[i][j] * texte[j];
            j++;
        }
        caracteres[i] = (c + cle[n][i]) % BASE_MAX;
        i++;
    }

    return caracteres;
}

/**
 * \brief Exercice 5
 *  
 * Converti le chiffré qui est un tableau d'entiers
 * sous la forme d'une chaine de caractère.
 */
char *Hill_affine_chiffre_en_chaine(char *texte, int **cle, int n)
{
    int i;
    char *chiffre_chaine;
    int *chiffre;

    chiffre = Hill_affine_chiffre(texte, cle, n);
    chiffre_chaine = malloc(n * sizeof(char));
    i = 0;
    while (i < n)
    {
        if (chiffre[i] > 0 && chiffre[i] < 26)
            chiffre_chaine[i] = chiffre[i] + '`';
        if (chiffre[i] == 26)
            chiffre_chaine[i] = ',';
        if (chiffre[i] == 27)
            chiffre_chaine[i] = ' ';
        if (chiffre[i] == 28)
            chiffre_chaine[i] = '.';
        i++;
    }
    return chiffre_chaine;
}

/**
 * \brief Exercice 4
 */
int *Hill_affine_dechiffre(char *texte, int **cle, int n)
{
}

/**
 * \brief Exercice 6
 * 
 * Converti le chiffré sous forme de tableau d'entiers modulo 29
 * vers une chaine de caractère.
 */
char *Hill_affine_dechiffre_en_chaine(char *texte, int **cle, int n)
{
    int i;
    char *chiffre_chaine;
    int *chiffre;

    chiffre = Hill_affine_dechiffre(texte, cle, n);
    chiffre_chaine = malloc(n * sizeof(char));
    i = 0;
    while (i < n)
    {
        if (chiffre[i] > 0 && chiffre[i] < 26)
            chiffre_chaine[i] = chiffre[i] + '`';
        if (chiffre[i] == 26)
            chiffre_chaine[i] = ',';
        if (chiffre[i] == 27)
            chiffre_chaine[i] = ' ';
        if (chiffre[i] == 28)
            chiffre_chaine[i] = '.';
        i++;
    }
    return chiffre_chaine;
}