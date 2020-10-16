#include <stdio.h>
#include <stdlib.h>

int factorielle(int n);
float coefficient(int n, int k);
int afficher_coeffs(int n);

int main()
{
	int x, y, n;
	printf("Entrer les nombre x, y et n:\n");
	printf("x=");
	scanf("%d", &x);
	printf("y=");
	scanf("%d", &y);
	printf("n=");
	scanf("%d", &n);

	/* PARTIE UNE DE L'EXERCICE */
	afficher_coeffs(n);

	/* PARTIE DEUX DE L'EXERCICE */
	int somme = 0;
	for (int k = 0; k <= n; k++)
	{
		int xx = 1, yy = 1;
		for (int i = 0; i < n - k; i++)
			xx *= x;
		for (int i = 0; i < k; i++)
			yy *= y;

		somme += coefficient(n, k) * xx * yy;
	}

	printf("(%d + %d) ^ %d = %d", x, y, n, somme);
}

int afficher_coeffs(int n)
{
	for (int k = 0; k <= n; k++)
	{
		printf("%lf\n", coefficient(n, k));
	}
}

float coefficient(int n, int k)
{
	return (float)factorielle(n) / (factorielle(k) * factorielle(n - k));
}

int factorielle(int n)
{
	if (n < 0)
	{
		printf("n ne peut pas être négatif!\n");
		exit(EXIT_FAILURE);
	}
	int j = 1;
	for (int i = n; i > 0; i--)
		j *= i;
	return j;
}
