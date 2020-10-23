#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;

	printf("Choisir 3 entiers:\n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	int minimum = a > b ? b : a;
	minimum = minimum > c ? c : minimum;

	printf("Minimum = %d\n", minimum);
}