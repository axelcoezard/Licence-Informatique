#include <stdio.h>

int main()
{
	int moyenne = 0, taille = 0;
	int chiffre;
	printf("Entrer un entier positif : ");
	scanf("%d", &chiffre);
	while (chiffre != -1)
	{
		moyenne += chiffre;
		taille++;
		printf("Entrer un entier positif : ");
		scanf("%d", &chiffre);
	}
	moyenne /= taille;
	printf("La moyenne de ces %d entiers vaut %d\n", taille, moyenne);
}