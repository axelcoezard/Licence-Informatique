#include <stdio.h>

#define N 10

int rechercheSeq(int *T, int x);

int main()
{
	int A[N] = {-1, 2, 3, -4, 6};

	int x;
	printf("Entrer un nombre x: ");
	scanf("%d", &x);
	int index = rechercheSeq(A, x);

	printf("T[%d] = %d\n", index, x);
}

int rechercheSeq(int *T, int x)
{
	for (int index = 0; index < N; index++)
		if (T[index] == x)
			return index;
	return -1;
}