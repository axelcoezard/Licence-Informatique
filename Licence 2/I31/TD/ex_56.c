#include <stdio.h>

int main()
{
	int somme = 0, n;
	printf("Somme des N premiers entiers. N= ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		somme += i + 1;
	printf("La somme des %d premiers entiers vaut %d\n", n, somme);
}