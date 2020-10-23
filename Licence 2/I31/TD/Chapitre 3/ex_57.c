#include <stdio.h>

float version_1(int n, float x);
float version_2(int n, float x);

int main()
{
	int n;
	float x;
	printf("Entrer un entier n: ");
	scanf("%d", &n);
	printf("Entrer un flottant x: ");
	scanf("%f", &x);

	float result_1 = version_1(n, x);
	float result_2 = version_2(n, x);

	printf("Resultat 1: %f\n", result_1);
	printf("Resultat 2: %f\n", result_2);
}

float version_1(int n, float x)
{
	float result = 0;
	for (int i = 0; i < n; i++)
		result += x;
	return result;
}

float version_2(int n, float x)
{
	int i = 0;
	float result = 0;
	while (i < n)
	{
		result += x;
		i++;
	}
	return result;
}