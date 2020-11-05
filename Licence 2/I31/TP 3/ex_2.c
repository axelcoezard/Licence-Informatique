#include <stdlib.h>
#include <stdio.h>

int main()
{
	/* CREATION ET ECRITURE */
	FILE *f = fopen("mes_caracteres.txt", "w+");
	char c;
	while ((c = (char)fgetc(stdin)) != '\n')
		fputc(c, f);
	fclose(f);

	/* LECTURE */
	FILE *f_bis = fopen("mes_caracteres.txt", "r+");
	char c_bis;
	while ((c_bis = (char)fgetc(f_bis)) != EOF)
		fputc(c_bis, stdout);
	fclose(f_bis);
}