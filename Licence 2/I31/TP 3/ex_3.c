#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *entree = fopen("entree.txt", "r+");
	FILE *sortie = fopen("sortie.txt", "w+");
	char c_bis;
	while ((c_bis = (char)fgetc(entree)) != EOF)
		fputc(c_bis, sortie);
	fclose(entree);
	fclose(sortie);
}