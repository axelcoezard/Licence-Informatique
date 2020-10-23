#include <stdio.h>

int jumeaux(int a, int b);

int main()
{
}

int est_premier(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return 0;

	return 1;
}

int jumeaux(int a, int b)
{
	return est_premier(a) && est_premier(b) && a == b + 2;
}
