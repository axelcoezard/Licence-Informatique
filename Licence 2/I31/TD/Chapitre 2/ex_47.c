#include <stdio.h>
#include <math.h>

int main()
{
	int a;

	printf("Choisir un entier:\n");
	scanf("%d", &a);
	printf("Parité = %s\n", a % 2 == 0 ? "Pair" : "Impair");
}