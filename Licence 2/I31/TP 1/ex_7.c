#include <stdio.h>

typedef union
{
	int entier;
	float reel;
} entreel;

int main()
{
	entreel f;
	printf("Entrer un réel:\n");
	scanf("%f", &f.reel);
	printf("%d", f.entier >> 15);
	/*
		TODO: Calculer la mantisse, le signe et l'exposant.
	*/
	printf("Le réeel [%f] est codé comme [%e][%f].");
}