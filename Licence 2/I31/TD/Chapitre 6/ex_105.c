#include <stdio.h>

int main()
{
	int i;
	int *p;
	p = &i;
	i = 1;
	printf("%d\n", i);
	*p = 2;
	printf("%d\n", *p);
}