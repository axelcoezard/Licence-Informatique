#include <stdio.h>

int main()
{
	int lastNombre;
	printf("Entrer 10 nombres:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("Nombre %d: ", i + 1);
		scanf("%d", &lastNombre);
		if (lastNombre < 0)
			break;
	}
	printf("Premier nombres négatifs: %d\n", lastNombre);
}