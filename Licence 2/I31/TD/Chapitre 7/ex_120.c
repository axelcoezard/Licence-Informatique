#include <stdio.h>

#define N 5

int fusion(int A[], int B[], int C[]);

int main()
{
	int A[N] = {-1, 2, 3, 7, 9};
	int B[N] = {-3, 8, 10, 12, 15};
	int C[N * 2];

	fusion(A, B, C);

	for (int i = 0; i < N * 2; i++)
		printf("%d\n", C[i]);
}

int fusion(int A[], int B[], int C[])
{
	for (int i = 0; i < N; i++)
	{
		C[i] = A[i];
		C[i + N] = B[i];
	}
}