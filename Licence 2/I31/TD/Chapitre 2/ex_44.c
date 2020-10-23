#include <stdio.h>
#include <math.h>

int main()
{
	float n;

	printf("Choisir un nombre:\n");
	scanf("%f", &n);
	printf("Racine de %f = %f\n", n, sqrt(n));
}