#include <stdio.h>
#include <math.h>

int echange(int *x, int *y);

int main()
{
	int x, y;
	printf("Entrer un nombre x: ");
	scanf("%d", &x);
	printf("Entrer un nombre y: ");
	scanf("%d", &y);
	echange(&x, &y);
	printf("x=%d; y=%d\n", x, y);
}

int echange(int *x, int *y)
{
	int tmp = *y;
	*y = *x;
	*x = tmp;
}