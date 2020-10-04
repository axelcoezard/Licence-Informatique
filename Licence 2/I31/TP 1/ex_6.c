#include <stdio.h>

#define TYPE int

void fonction(TYPE n);

int main()
{
	int a = 5;
	fonction(a);
}

void fonction(TYPE n)
{
	TYPE i;
	int j, taille;
	taille = 8 * sizeof(TYPE);
	for (j = 0; j < taille; j++)
	{
		i = 1 << (taille - j - 1);
		if (n & i)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}