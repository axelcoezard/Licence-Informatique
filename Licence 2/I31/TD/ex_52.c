#include <stdio.h>

int main()
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
}