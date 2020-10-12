#include <stdio.h>

int f1(int i) { return i + 1; }
int f2(int i) { return i++; }

int f3(int i)
{
	printf("f3 : %d\n", i == 0);
	return i;
}

int f4(int i)
{
	printf("f4 : %d\n", i = 0);
	return i;
}

int main()
{
	int a, b;
	a = f1(0);
	b = f2(1);
	printf("1 : a=%d, b=%d\n", a, b);
	a = f3(a);
	b = f4(a);
	printf("2 : a=%d, b=%d\n", a, b);
}