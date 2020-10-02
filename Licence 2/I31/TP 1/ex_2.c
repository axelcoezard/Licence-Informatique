#include <stdio.h>
#include <math.h>

#define PRINT(int) printf("%d\n", int)

int main()
{
	exo_12();
	exo_14();
}

void exo_12()
{
	int x, y, z;
	x = 2;
	y = 1;
	z = 0;
	x = x && y || z;
	PRINT(x);
	PRINT(x * x || !y && z);
	x = y = z;
	z = x++ - 1;
	PRINT(x);
	PRINT(z);
	z += -x++ + ++y;
	PRINT(x);
	PRINT(z);
	z = x / ++x;
	PRINT(z);
}

void exo_14()
{
	int x;
	x = -3 + 4 * 5 - 6;
	printf("%d\n", x);
	x = 3 + 4 % 5 - 6;
	printf("%d\n", x);
	x = -3 * 4 % -6 / 5;
	prinf("%d\n", x);
	x = (7 + 6) % 5 / 2;
	printf("%d\n", x);
}