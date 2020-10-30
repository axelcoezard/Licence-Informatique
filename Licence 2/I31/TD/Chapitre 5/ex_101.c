#include <stdio.h>

int main()
{
	const int N = 10;
	int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int x;
	printf("Entrer un x: ");
	scanf("%d", &x);

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