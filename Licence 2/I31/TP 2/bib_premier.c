#include <stdio.h>
#include <stdlib.h>

int est_premier(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return 0;

	return 1;
}

void premiers_premier(int n)
{
	if (!est_premier(n))
		exit(EXIT_FAILURE);

	for (int i = 0; i < n; i++)
		if (est_premier(i))
			printf("%d est aussi un nombre premier\n", i);
}