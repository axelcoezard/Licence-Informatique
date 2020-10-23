#include <stdio.h>

int main()
{
	int n;
	printf("Entrer un nombre N: ");
	scanf("%d", &n);

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}
}