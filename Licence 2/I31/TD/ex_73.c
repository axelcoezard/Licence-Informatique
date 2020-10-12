#include <stdio.h>

void f1()
{
	printf("bonjour\n");
}

void f2(int n)
{
	for (int i = 0; i < n; i++)
		printf("bonjour\n");
}

int f3(int n)
{
	f2(n);
	return 0;
}

int main()
{
	f1();
	f2(10);
	f3(10);
}