#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char conversion_caractere(char c);

int main()
{
	char c;
	printf("Entrer une lettre c: ");
	scanf("%c", &c);

	printf("En majuscule, %c devient %c\n", c, conversion_caractere(c));
}

char conversion_caractere(char c)
{
	if (!isalpha(c))
	{
		printf("c doit être une lettre!\n");
		exit(EXIT_FAILURE);
	}
	return toupper(c);
}