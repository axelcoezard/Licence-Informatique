#include <stdio.h>

int maximum(int x, int y);

int main()
{
	printf("%d\n", maximum(-1, 8));
}

int maximum(int x, int y)
{
	return x == y ? 0 : (x > y ? x : y);
}