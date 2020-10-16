#include <stdio.h>

int moyenne(int *valeurs, int size);
int variance(int *valeurs, int size);

int main()
{
	int valeurs[100];
	int valeurs_size = 0;
	do
	{
		printf("Entrer un nombre n (-1 pour arrêter):");
		scanf("%d", &valeurs[valeurs_size++]);
	} while (valeurs[valeurs_size - 1] >= 0);
	valeurs_size--;

	int moy = moyenne(valeurs, valeurs_size);
	int var = variance(valeurs, valeurs_size);

	printf("Moyenne: %d\n", moy);
	printf("Variance: %d\n", var);
}

int moyenne(int *valeurs, int size)
{
	int moyenne = 0;
	for (int i = 0; i < size; i++)
		moyenne += valeurs[i];
	return moyenne / size;
}

int variance(int *valeurs, int size)
{
	int variance = 0;
	int moy = moyenne(valeurs, size);
	for (int i = 0; i < size; i++)
	{
		int term = (valeurs[i] - moy);
		variance += term * term;
	}
	return variance / size;
}