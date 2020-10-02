#include <stdio.h>

int main()
{
	int x, y, m;
	printf("Entrer deux entiers x et y:\n");
	printf("x = ");
	scanf("%d", &x);
	printf("y = ");
	scanf("%d", &y);

	m = x > y ? x : y;

	printf("\nLe maximum m de x et y est: %d\n", m);

	return 0;
}