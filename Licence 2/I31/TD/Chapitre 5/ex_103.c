#include <stdio.h>

#define N 10

int main()
{
	int vecteurs[2][N] = {{-1, 2, 3, 5, 2, 8, -3, 9, 7, 6},
												{2, 3, 8, 9, 7, 1, -4, -5, 6, 9}};

	int prod_scal = 0;
	for (int i = 0; i < N; i++)
		prod_scal += vecteurs[0][i] * vecteurs[1][i];

	printf("%d\n", prod_scal);
}