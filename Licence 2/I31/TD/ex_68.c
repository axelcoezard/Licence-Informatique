#include <stdio.h>

int main()
{
	int lastNombre = 1, produit = 1;
	do
	{
		printf("Entrer un nombre strictement positif svp: ");
		scanf("%d", &lastNombre);
	} while (lastNombre < 0);
	printf("Merci.");
}