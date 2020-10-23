#include <stdio.h>

int lePlusProcheDe10(int x, int y);

int main()
{
	int x, y;
	printf("Entrer un nombre x: ");
	scanf("%d", &x);
	printf("Entrer un nombre y: ");
	scanf("%d", &y);
	printf("%d\n", lePlusProcheDe10(x, y));
}

int lePlusProcheDe10(int x, int y)
{
	int d1 = x > 10 ? x - 10 : 10 - x;
	int d2 = y > 10 ? y - 10 : 10 - y;
	return d1 == d2 ? (x > y ? x : y) : (d1 < d2 ? x : y);
}