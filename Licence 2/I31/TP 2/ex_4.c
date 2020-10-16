#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Entrer un nombre n: ");
	scanf("%d", &n);

	if (n < 0)
	{
		printf("Veuillez rentrer un nombre > 0");
		exit(EXIT_FAILURE);
	}

	int s = 0;
	for (int i = 1; i < n + 1; i++)
		s += i * i;

	printf("Somme des carrés de 1 à %d = %d\n", n, s);
}