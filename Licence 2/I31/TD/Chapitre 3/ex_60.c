#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	printf("Entrer un nombre N: ");
	scanf("%d", &n);

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < i * 2; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}