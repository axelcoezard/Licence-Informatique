#include <stdio.h>

int lePlusProcheDe10(int x, int y);

int main()
{
	printf("%d\n", Absolue(-1));
}

int lePlusProcheDe10(int x, int y)
{
	return x < 0 ? -x : x;
}