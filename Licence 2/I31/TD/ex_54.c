#include <stdio.h>

int version_1(int *entiers);
int version_2(int *entiers);
int version_3(int *entiers);

int main()
{
	int entiers[5];
	printf("Choisir 5 entiers: ");
	scanf("%d %d %d %d %d", &entiers[0], &entiers[1], &entiers[2], &entiers[3], &entiers[4]);

	int result_1 = version_1(entiers);
	int result_2 = version_2(entiers);
	int result_3 = version_3(entiers);

	printf("%d\n", result_1);
	printf("%d\n", result_2);
	printf("%d\n", result_3);
}

int version_1(int *entiers)
{
	int result = 0;
	for (int i = 0; i < 5; i++)
		result += entiers[i];
	return result;
}

int version_2(int *entiers)
{
	int i = 0, result = 0;
	while (i < 5)
		result += entiers[i++];
	return result;
}

int version_3(int *entiers)
{
	int i = 0, result = 0;
	do
	{
		result += entiers[i++];
	} while (i < 5);
	return result;
}