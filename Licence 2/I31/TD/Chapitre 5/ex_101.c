#include <stdio.h>

int main()
{
	int N = 10, x = 5;
	int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int isFind = 0;
	for (int i = 0; i < N; i++)
		if (isFind || A[i] == x)
		{
			isFind = 1;
			A[i] = A[i + 1];
		}
	if (isFind)
		N--;

	for (int i = 0; i < N; i++)
		printf("%d\n", A[i]);
}