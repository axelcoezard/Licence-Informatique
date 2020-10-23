#include <stdio.h>

int main()
{
	int lastNombre = 1, produit = 1;
	printf("Entrer des nombres:\n");
	do
	{
		produit *= lastNombre;
		scanf("%d", &lastNombre);
	} while (0 <= lastNombre && lastNombre <= 20);
	printf("Produit des nombres: %d\n", produit);
}