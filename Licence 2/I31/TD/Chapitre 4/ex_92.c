#include <stdio.h>
#include <math.h>

int serieGeometrique(int x, int n);

int main()
{
	int x, n;
	printf("Entrez un nombre x:");
	scanf("%d", &x);
	printf("Entrez un nombre n:");
	scanf("%d", &n);
	printf("La série des x=%d et n=%d est égale à %d\n", x, n, serieGeometrique(x, n));
}

int serieGeometrique(int x, int n)
{
	int somme = 0;
	for (int i = 0; i <= n; i++)
	{
		somme += pow(x, i);
	}
	return somme;
}
