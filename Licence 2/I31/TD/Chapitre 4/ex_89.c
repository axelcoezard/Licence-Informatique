#include <stdio.h>

int estDivisiblePar(int x, int y);
int estParfait(int x);

int main()
{
	int n, i = 1, count = 0;
	printf("Entrer un nombre n: ");
	scanf("%d", &n);

	while (count < n)
	{
		if (estParfait(i))
		{
			printf("%d est parfait.\n", i);
			count++;
		}
		i++;
	}
}

int estDivisiblePar(int x, int y)
{
	return x % y == 0;
}

int estParfait(int x)
{
	int somme = 0;
	for (int i = 1; i < x; i++)
	{
		if (estDivisiblePar(x, i))
			somme += i;
	}
	return somme == x;
}