#include <stdio.h>
#include <math.h>

int main()
{
	float a, b;

	printf("Choisir deux entiers a et b:\n");
	scanf("%f", &a);
	scanf("%f", &b);
	printf("Somme = %f; Différence = %f\n", a + b, a - b);
}