#include <stdio.h>

int main()
{
	int n;
	printf("Entrer un entier n: ");
	scanf("%d", &n);

	if (est_premier(n))
		printf("%d est premieeeer\n", n);
	else
		printf("%d n'est pas premier\n", n);
	premiers_premier(n);
}
