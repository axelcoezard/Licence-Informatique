#include <stdio.h>

void changeSigne(int *tab, int taille);

int main()
{
	int A[5] = {-1, 2, 3, -4, 6};
	changeSigne(A, 5);
	for (int i = 0; i < 5; i++)
		printf("%d\n", A[i]);
}

void changeSigne(int *tab, int taille)
{
	for (int i = 0; i < taille; i++)
		tab[i] = -tab[i];
}
