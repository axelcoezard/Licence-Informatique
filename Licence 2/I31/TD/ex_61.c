#include <stdio.h>

int main()
{
	int N, u1 = 1, u2 = 1;

	printf("Entrer un N > 2: ");
	scanf("%d", &N);

	for (int i = 2; i < N; i++)
	{
		int tmp = u2;
		u2 = u2 + u1;
		u1 = tmp;
	}

	printf("Fibonacci(%d)=%d\n", N, u2);
}