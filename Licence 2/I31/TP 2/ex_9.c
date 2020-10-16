#include <stdio.h>
#include <stdlib.h>

int puissance(int x, int n);

int main()
{
	int x, n;
	printf("Entrer un nombre x et sa puissance n: \n");
	printf("x=");
	scanf("%d", &x);
	printf("n=");
	scanf("%d", &n);
	printf("Puissance(%d, %d)=%d\n", x, n, puissance(x, n));
}

int puissance(int x, int n)
{
	if (n < 0)
	{
		printf("n ne peut pas être négatif!\n");
		exit(EXIT_FAILURE);
	}
	int p = 1;
	for (int i = 0; i < n; i++)
		p *= x;
	return p;
}