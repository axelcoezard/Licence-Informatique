#include <stdio.h>
#include <stdlib.h>

#define NBLIGNES 10
#define NBCAR 50

int main()
{
	FILE *texte = fopen("mon_texte.txt", "w+");
	for (int i = 0; i < NBLIGNES; i++)
		fputs("Ceci est une ligne\n", texte);
	fclose(texte);

	FILE *texte_bis = fopen("mon_texte.txt", "r+");
	char c;
	while ((c = (char)fgetc(texte_bis)) != EOF)
		fputc(c, stdout);
	fclose(texte_bis);
}