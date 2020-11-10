#include <stdio.h>

int moyenne(int *tab, int taille);

int main()
{
	int A[5] = {-1, 2, 3, -4, 6};
	int moy = moyenne(A, 5);
	printf("%d\n", moy);
}

int moyenne(int *tab, int taille)
{
	int moyenne = 0;
	for (int i = 0; i < taille; i++)
		moyenne += tab[i];
	return moyenne / taille;
}