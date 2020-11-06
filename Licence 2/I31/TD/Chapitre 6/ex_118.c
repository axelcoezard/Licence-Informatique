#include <stdio.h>

#define N 5

int miroir(int *tab);

int main()
{
	int A[N] = {-1, 2, 3, -4, 6};
	miroir(A);
	for (int i = 0; i < N; i++)
		printf("%d\n", A[i]);
}

int miroir(int *tab)
{
	int tmp;
	for (int i = 0; i < N / 2; i++)
	{
		tmp = tab[i];
		tab[i] = tab[N - i - 1];
		tab[N - i - 1] = tmp;
	}
}