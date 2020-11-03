#include <stdio.h>

#define N 7

int main()
{
	int A[N] = {1, 2, 5, 6, 8, 9, 12};

	int x;
	printf("Entrer un nombre x: ");
	scanf("%d", &x);

	int i = 0;
	while (A[i] != x && i < N)
		i++;
	if (i < N - 1)
		return 0;

	int tmp[N + 1];
	int changed = 0;
	for (int i = 0; i < N + 1; i++)
	{
		if (x > A[i] || changed)
		{
			tmp[i + changed] = A[i];
			continue;
		}
		tmp[i] = x;
		tmp[i + 1] = A[i];
		changed = 1;
	}

	for (int i = 0; i < N + 1; i++)
	{
		printf("%d ", tmp[i]);
	}
}