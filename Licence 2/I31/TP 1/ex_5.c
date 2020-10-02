#include <stdio.h>

int main()
{
	int c_date;

	printf("Entrer une date au format yyyymmdd: ");
	scanf("%d", &c_date);

	int day = c_date % 100;
	int month = c_date / 100 % 100;
	int year = c_date / 10000;

	printf("Jour: %d;\nMois: %d;\nAnnée: %d;\n", day, month, year);

	return 0;
}
