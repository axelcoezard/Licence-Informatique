#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	printf("Entrer un nombre N: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < pow(2, i); j++)
		{
			printf("*");
		}
		printf(" \n");
	}
}