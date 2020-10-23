#include <stdio.h>

int sommeDesImpairs(int n);

int main()
{
}

int sommeDesImpairs(int n)
{
	int somme = 0;
	for (int i = 0; i < n + 1; i++)
	{
		if (i % 2 == 1)
			somme += i;
	}
	return somme;
}