#include <stdio.h>

int main()
{
	int continuer = 1;

	while (continuer)
	{
		int a, b;
		char op;
		printf("Entrer une opération (format:d op[+-*/] d):");
		scanf("%d %c %d", &a, &op, &b);
		switch (op)
		{
		case '+':
			printf("%d\n", a + b);
			break;
		case '-':
			printf("%d\n", a - b);
			break;
		case '*':
			printf("%d\n", a * b);
			break;
		case '/':
			printf("%d\n", a / b);
		}
		printf("Voulez-vous continuer ? (1 = oui, 0 = non) :");
		scanf("%d", &continuer);
	}
}