#include <stdio.h>

int main()
{
	int n;
	printf("Entrer un nombre n: ");
	scanf("%d", &n);

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			printf("Non premier");
			return 0;
		}
	}

	printf("Premier");
	return 1;
}