#include <stdio.h>

int reste(int x, int y);

int main()
{
	int x, y;
	printf("Entrer un nombre x: ");
	scanf("%d", &x);
	printf("Entrer un nombre y: ");
	scanf("%d", &y);
	printf("reste(%d, %d)=%d\n", x, y, reste(x, y));
}

int reste(int x, int y)
{
	/*
		CALCULER LE RESTE DE LA DIVISION DE X PAR Y.
	*/
}