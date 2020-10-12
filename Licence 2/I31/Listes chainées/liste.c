#include <stdio.h>

typedef struct
{
	int valeur;
	Maillon *suivant;
} Maillon;

int liste_vide(Maillon *tete);
void add_liste(Maillon **tete, int valeur);
int recherche(Maillon *tete, int valeur);

int main()
{
}

int liste_vide(Maillon *tete)
{
	return (tete == NULL);
}

void add_liste(Maillon **tete, int valeur)
{
	Maillon *nouveau;
	nouveau = (Maillon *)malloc(sizeof(Maillon));
	nouveau->valeur = valeur;
	nouveau->suivant = *tete;
	*tete = nouveau;
}

int recherche(Maillon *tete, int valeur)
{
	Maillon *ptr;
	ptr = tete;
	while (ptr != NULL)
	{
		if (ptr->valeur = valeur)
			return 1;
		ptr = ptr->suivant;
	}
	return 0;
}

void supprime(Maillon **l, int valeur)
{
	Maillon *ptr, *prec = NULL;
	ptr = *l;
	if (ptr != NULL)
	{
		while (ptr != NULL && ptr->valeur != valeur)
		{
			prec = ptr;
			ptr = ptr->suivant;
		}
		if (ptr != NULL)
		{
			if (prec == NULL)
				*l = ptr->suivant;
			else
				prec->suivant = ptr->suivant;
		}
		free(ptr);
	}
}