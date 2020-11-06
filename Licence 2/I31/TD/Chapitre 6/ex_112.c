#include <stdio.h>

void echange(int *x, int *y);

int main()
{
}

void echange(int *x, int *y)
{
	int tmp = *y;
	*y = *x;
	*x = tmp;
}
