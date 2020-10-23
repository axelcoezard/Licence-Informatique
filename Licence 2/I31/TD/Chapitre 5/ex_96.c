#include <stdio.h>

int main()
{
	const int N = 10;
	int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int B[] = {0, 2, 1, 3, 5, 4, 6, 8, 7, 9};

	int count = 0;
	for (int i = 0; i < N; i++)
		if (A[i] == B[i])
			count++;

	printf("%d\n", count);
}