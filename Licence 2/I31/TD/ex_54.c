#include <stdio.h>

int version_1();
int version_2();
int version_3();

int main()
{
	int result_1 = version_1();
	int result_2 = version_2();
	int result_3 = version_3();

	printf("%d\n", result_1);
	printf("%d\n", result_2);
	printf("%d\n", result_3);
}

int version_1()
{
	printf("Choisir 5 entiers: ");
	int lastNombre, result = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &lastNombre);
		result += lastNombre;
	}
	return result;
}

int version_2()
{
	printf("Choisir 5 entiers: ");
	int lastNombre, i = 0, result = 0;
	while (i < 5)
	{
		scanf("%d", &lastNombre);
		result += lastNombre;
		i++;
	}
	return result;
}

int version_3()
{
	printf("Choisir 5 entiers: ");
	int lastNombre, i = 0, result = 0;
	do
	{
		scanf("%d", &lastNombre);
		result += lastNombre;
		i++;
	} while (i < 5);
	return result;
}