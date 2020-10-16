#include <stdio.h>

int main()
{
	int n;
	printf("Entrer un nombre n:");
	scanf("%d", &n);

	int q = n, index = 0;
	do
	{
		q /= 10;
		index++;
	} while (q > 0);

	printf("%d est composé de %d chiffres\n", n, index);
}