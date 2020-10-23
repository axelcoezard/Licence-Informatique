#include <stdio.h>

int main()
{
	const int N = 8;
	int A[] = {0, -1, 8, 9, 18, 2, 3, 4};

	int max = A[0], max_i = 0;
	for (int i = 1; i < N; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
			max_i = i;
		}
	}

	printf("A[%d] = %d est le plus grand élement.\n", max_i, max);
}