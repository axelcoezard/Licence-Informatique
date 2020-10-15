#include <stdio.h>

int sommeDesEntiers(int n);

int main()
{
	int n;
	printf("Entrer un nombre n: ");
	scanf("%d", &n);
	printf("sommeDesEntiers(%d)=%d\n", n, sommeDesEntiers(n));
}

int sommeDesEntiers(int n)
{
	int s = 0;
	for (int i = 1; i < n + 1; i++)
		s += i;
	return s;
}