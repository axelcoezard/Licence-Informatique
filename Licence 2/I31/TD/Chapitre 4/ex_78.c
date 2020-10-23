#include <stdio.h>
#include <stdlib.h>

int factorielle(int n);

int main()
{
	int n;
	printf("Entrer un nombre n: ");
	scanf("%d", &n);
	printf("Factorielle(%d)=%d\n", n, factorielle(n));
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