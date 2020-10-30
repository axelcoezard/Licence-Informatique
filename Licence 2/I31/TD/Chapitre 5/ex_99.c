#include <stdio.h>
int main()
{
	const int N = 5;
	int nombres[N];

	for (int i = 0; i < N; i++)
	{
		printf("Entrer un %dème nombre: ", i);
		scanf("%d", &nombres[i]);
	}

	for (int i = 0; i < N; i++)
		printf("%d\n", nombres[N - i - 1]);
}