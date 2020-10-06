#include <stdio.h>

int main()
{
	int somme = 0, chiffre;
	do
	{
		printf("Entrer un entier : ");
		scanf("%d", &chiffre);
		if (chiffre != -1)
			somme += chiffre;
	} while (chiffre != -1);
	printf("La somme de ces entiers vaut %d\n", somme);
}