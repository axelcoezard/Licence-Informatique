#include <stdio.h>

int main()
{
	const int N = 5;
	int nombres[N];
	int tmp;

	printf("Entrer un 1er nombre: ");
	scanf("%d", &nombres[0]);
	for (int i = 1; i < N; i++)
	{
		printf("Entrer un %dème nombre: ", i);
		scanf("%d", &tmp);

		if (nombres[i - 1] > tmp)
		{
			nombres[i] = nombres[i - 1];
			nombres[i - 1] = tmp;
			continue;
		}
		nombres[i] = tmp;
	}

	for (int i = 0; i < N; i++)
		printf("%d\n", nombres[i]);
}