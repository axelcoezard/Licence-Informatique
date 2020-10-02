#include <stdio.h>
#define PI 3.141581

int main()
{
	float rayon;

	printf("Choisir un rayon de cercle:\n");
	scanf("%f", &rayon);
	printf("Diametre = %f; Circonférence = %f\n", rayon * 2, rayon * PI * 2);
}