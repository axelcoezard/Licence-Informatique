#include <stdio.h>

int sommeDesProduits(int n);

int main()
{
	int n;
	printf("Entrer un nombre n: ");
	scanf("%d", &n);
	printf("sommeDesProduits(%d)=%d\n", n, sommeDesProduits(n));
}

int sommeDesProduits(int n)
{
	int s = 0;
	for (int j = 2; j <= n; j++)
		for (int i = 2; i <= j; i++)
			s += j * i;
	return s;
}