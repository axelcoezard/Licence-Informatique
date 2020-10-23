#include <stdio.h>

int main()
{
	int nombres[10];
	int negatifs = 0;
	printf("Entrer 10 nombres:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("Nombre %d: ", i + 1);
		scanf("%d", &nombres[i]);
		if (nombres[i] < 0)
			negatifs++;
	}
	printf("Nombres de nombres négatifs: %d\n", negatifs);
}