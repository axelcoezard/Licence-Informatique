#define LCOTE 10
#define LTITRE 50
#define LANNEE 5
#define LNOM 50

void ecrire_livre(char *cote, char *titre, int annee);
int ecrire_auteur(char *nom, char *cote);
int lire_livre(char *cote, char *titre, int *annee);
int lire_auteur(char *nom, char *cote);
void livres_publies_apres(int annee_inferieure);
void auteurs_du_livre(char *titre);