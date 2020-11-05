#include <stdio.h>
#include <stdlib.h>

#include "ex_6.h"

FILE *flivres, *fauteurs;

int main()
{
	flivres = fopen("livres.txt", "rw+");
	fauteurs = fopen("auteurs.txt", "rw+");

	ecrire_livre("L3", "Alice aux pays des ordi", 2021);
	ecrire_auteur("Jean Pierre", "L3");
}

void ecrire_livre(char *cote, char *titre, int annee)
{
	char annee_s[LANNEE];
	sprintf(annee_s, "%d", annee);

	fseek(flivres, 0, SEEK_END);
	fputc('\n', flivres);
	fputs(cote, flivres);
	fputc('\n', flivres);
	fputs(titre, flivres);
	fputc('\n', flivres);
	fputs(annee_s, flivres);
}

int ecrire_auteur(char *nom, char *cote)
{
	fseek(fauteurs, 0, SEEK_END);
	fputc('\n', fauteurs);
	fputs(nom, fauteurs);
	fputc('\n', fauteurs);
	fputs(cote, fauteurs);
}
