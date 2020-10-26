#include <stdio.h>

void modif(char *chaine);

int main()
{
}

void modif(char *chaine)
{
	int i = 0;
	while (chaine[i] != '\0')
	{
		if (chaine[i] == 'e')
			chaine[i] = 'E';
		i += 1;
	}
}