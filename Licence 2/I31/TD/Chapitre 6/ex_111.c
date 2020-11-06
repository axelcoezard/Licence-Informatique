#include <stdio.h>

void carre(int *x);

int main()
{
	int b;
	printf("Entrer un nombre: ");
	scanf("%d", b);

	carre(&b);
	printf("%d\n", b);
}

void carre(int *x)
{
	*x *= *x;
}