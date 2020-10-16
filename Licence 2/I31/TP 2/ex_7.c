#include <stdio.h>
#include <stdlib.h>

int pgcd(int p, int q);
int ppcm(int p, int q);

int main()
{
	int p, q;
	printf("Entrer les nombre p et q:\n");
	printf("p=");
	scanf("%d", &p);
	printf("q=");
	scanf("%d", &q);

	printf("Pgcd(%d, %d)=%d\n", p, q, pgcd(p, q));
	printf("ppcm(%d, %d)=%d\n", p, q, ppcm(p, q));
}

int pgcd(int p, int q)
{
	int max = p > q ? p : q;
	int min = max == p ? q : p;

	int quotient = 1, reste;

	while (reste != 0)
	{
		quotient = max / min;
		reste = max % min;
		max = min;
		min = reste;
	}

	return max;
}

int ppcm(int p, int q)
{
	return p * q / pgcd(p, q);
}