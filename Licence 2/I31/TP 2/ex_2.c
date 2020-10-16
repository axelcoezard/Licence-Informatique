#include <stdio.h>

int main()
{
	int n;
	printf("Entrer un nombre n:");
	scanf("%d", &n);

	int i = 0;
	while (i * i <= n)
		i++;
	printf("Le plus petit carre supérieur à %d est %d\n", n, i * i);
}