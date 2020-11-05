#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char *nom;
	char *prenom;
	char *numero;
	char *email;
} Personne;

int taille_annuaire(char *fichier);
void afficher_annuaire(char *fichier);
void ajouter_annuaire(Personne personne, char *fichier);

int main()
{
	Personne axel = {"Coézard", "Axel", "06 62 03 29 73", "axel.coezard@gmail.com"};
	ajouter_annuaire(axel, "annuaire.txt");
	afficher_annuaire("annuaire.txt");
}

int taille_annuaire(char *fichier)
{
	FILE *annuaire = fopen(fichier, "r+");
	int nbLignes = 0;
	char a;
	while ((a = fgetc(annuaire)) != EOF)
		if (a == '\n')
			nbLignes++;
	fclose(annuaire);
	return nbLignes + 1;
}

void afficher_annuaire(char *fichier)
{
	int nbLignes = taille_annuaire(fichier);

	FILE *annuaire = fopen(fichier, "r+");
	for (int i = 0; i < nbLignes; i++)
	{
		char nom[50], prenom[50], email[250];
		char a[3], b[3], c[3], d[3], e[3];
		fscanf(annuaire, "%s %s %s %s %s %s %s %s", nom, prenom, a, b, c, d, e, email);
		printf("Nom: %s\n", nom);
		printf("Prénom: %s\n", prenom);
		printf("Tel: %s %s %s %s %s\n", a, b, c, d, e);
		printf("Email: %s\n", email);
	}
	fclose(annuaire);
}

void ajouter_annuaire(Personne personne, char *fichier)
{
	int nbLignes = taille_annuaire(fichier);
	FILE *annuaire = fopen(fichier, "a");
	fputs(personne.nom, annuaire);
	fputc(' ', annuaire);
	fputs(personne.prenom, annuaire);
	fputc(' ', annuaire);
	fputs(personne.numero, annuaire);
	fputc(' ', annuaire);
	fputs(personne.email, annuaire);
	fputs("\n", annuaire);
	fclose(annuaire);
}