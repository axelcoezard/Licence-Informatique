#include <stdio.h>
#include <string.h>

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

int cherche_str(char *c, char *k)
{
	int ic, ik;
	int lc = len(c), lk = len(k);
	for (ic = 0; ic < lc - lk; ic++)
	{
		ik = 0;
		while (k[ik] != '\0' && k[ik] == c[ic + ik])
			ik += 1;
		if (k[ik] == '\0')
			return ic;
	}
	return -1;
}