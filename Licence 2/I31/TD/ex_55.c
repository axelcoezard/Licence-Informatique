#include <stdio.h>

int main()
{
	int moyenne = 0, taille = 0;
	int chiffre;
	do
	{
		printf("Entrer un entier positif : ");
		scanf("%d", &chiffre);
		if (chiffre != -1)
		{
			moyenne += chiffre;
			taille++;
		}
	} while (chiffre != -1);
	moyenne /= taille;
	printf("La moyenne de ces %d entiers vaut %d\n", taille, moyenne);
}