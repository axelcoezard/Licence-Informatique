#include <stdio.h>
#include <string.h>

int estPalimdrome(char tab[], int nb);

int main()
{
	char chaine[100];
	printf("Entrer une chaine: ");
	scanf("%s", chaine);
	printf("%s\n", chaine);

	int oui = estPalimdrome(chaine, strlen(chaine));
	printf("%d\n", oui);
}

int estPalimdrome(char tab[], int nb)
{
	int i = 0, j = nb % 2;
	while (i < nb / 2)
	{
		if (tab[i] == tab[nb - 1 - i])
			j += 2;
		i++;
	}
	return j == nb;
}