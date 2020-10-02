#include <stdio.h>
#include <math.h>

int main()
{
	float rayon;

	printf("Choisir un rayon d'une sphère:\n");
	scanf("%f", &rayon);
	printf("Surface = %f; Volume = %f\n", 4 * M_PI * pow(rayon, 2), 4 * M_PI * pow(rayon, 3) / 3);
}