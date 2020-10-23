#include <stdio.h>

void table(int n);

int main()
{
	printf("Tables de multiplication des nombres de 1 à 10:\n");
	for (int i = 0; i < 10; i++)
		table(i + 1);
}

void table(int n)
{
	printf("Table de %d:\n", n);
	for (int i = 1; i <= 10; i++)
	{
		printf("%dx%d=%d\n", n, i, n * i);
	}
	printf("\n");
}