#include <stdio.h>
#include <math.h>

int main()
{
	float cote;

	printf("Choisir la longueur du coté d'un carré:\n");
	scanf("%f", &cote);
	printf("Longueur diagonale = %f\n", sqrt(2 * pow(cote, 2)));
}