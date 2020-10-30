#include <stdio.h>

int main()
{
	const int N = 10;
	const int A[] = {0, 1, 5, 3, 4, 5, 6, 7, 8, 5};

	int x;
	printf("Entrer un x: ");
	scanf("%d\n", &x);

	for (int i = 0; i < N; i++)
		if (A[i] == x)
			printf("A[%d] = %d\n", i, x);
}