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
	int toSub = x, count = 0;
	while (toSub >= y)
	{
		toSub -= y;
		count++;
	}
	return toSub;
}