#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c;

	printf("Choisir une équation aX^2 + bX + c = 0:\n");
	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);

	if (a = 0)
		if (b != 0)
			printf("La solution est: x = %lf\n", -c / b);
		else
			printf("Aucune solution.\n");

	double delta = pow(b, 2) - 4 * a * c;
	printf("Delta = %lf\n", delta);

	if (delta < 0)
		printf("Aucune solution réelle.\n");
	else if (delta == 0)
		printf("Une seule solution: x = %lf \n", -b / 2 / a);
	else if (delta > 0)
		printf("Deux solutions:\n- x1 = %lf\n- x2 = %lf\n", (-b - sqrt(delta)) / a / 2, (-b + sqrt(delta)) / a / 2);
}