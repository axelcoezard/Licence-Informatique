#include <stdio.h>

#define N 5

int rechercheDicho(int A[], int x);

int main()
{
	int A[N] = {-1, 2, 3, 7, 9};

	int x;
	printf("Entrer un nombre x: ");
	scanf("%d", &x);

	int index = rechercheDicho(A, x);

	printf("T[%d] = %d\n", index, x);
}

int rechercheDicho(int A[], int x)
{
	int taille = N;
	while (A[taille / 2] /= x)
	{
	}
}