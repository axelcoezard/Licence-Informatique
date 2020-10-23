#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nbDeChiffres(int x);
int estPair(int x);
int extraitNombre(int x, int n, int lg);
int sommeDesChiffres(int x);

int main()
{
	int x = 45863047;
	printf("Entrer un nombre x: ");
	scanf("%d", &x);

	if (!estPair(x))
		exit(EXIT_FAILURE);

	int nC = nbDeChiffres(x);
	int eN_1 = extraitNombre(x, 0, floor(nC / 2));
	int eN_2 = extraitNombre(x, floor(nC / 2), nC);

	int estCouicable = sommeDesChiffres(eN_1) == sommeDesChiffres(eN_2);
	printf("%d est couicable ? : %s\n", x, estCouicable ? "Oui" : "Non");
}

int nbDeChiffres(int x)
{
	int nbr = 0;
	while (x > 0)
	{
		x /= 10;
		nbr++;
	}
	return nbr;
}

int estPair(int x)
{
	return nbDeChiffres(x) % 2 == 0;
}

int extraitNombre(int x, int n, int lg)
{
	return (int)(x / pow(10, n)) % (int)pow(10, lg);
}

int sommeDesChiffres(int x)
{
	int somme = 0, m;
	while (x >= 10)
	{
		m = floor(x / 10);
		somme += x - 10 * m;
		x = m;
	}
	return x + somme;
}