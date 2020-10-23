#include <stdio.h>

int Absolue(int x);

int main()
{
	printf("%d\n", Absolue(-1));
}

int Absolue(int x)
{
	return x < 0 ? -x : x;
}