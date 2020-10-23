#include <stdio.h>

int sommeDesCarres(int n);

int main()
{
	int n;
	printf("Entrer un nombre n: ");
	scanf("%d", &n);
	printf("sommeDesCarres(%d)=%d\n", n, sommeDesCarres(n));
}

int sommeDesCarres(int n)
{
	int s = 0;
	for (int i = 1; i < n + 1; i++)
		s += i * i;
	return s;
}