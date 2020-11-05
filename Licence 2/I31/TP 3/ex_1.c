#include <stdlib.h>
#include <stdio.h>

int main()
{
	char c;
	while ((c = (char)fgetc(stdin)) != '\n')
		fputc(c, stdout);
}