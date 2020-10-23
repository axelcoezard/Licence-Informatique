#include <stdio.h>

int main()
{
	int depart, trajet;

	printf("Choisir une heure de départ (format: hms): ");
	scanf("%d", &depart);
	printf("Choisir un temps de trajet (format: hms): ");
	scanf("%d", &trajet);

	int sd = depart % 100, md = depart / 100 % 100, hd = depart / 10000;
	int st = trajet % 100, mt = trajet / 100 % 100, ht = trajet / 10000;

	int sa = (sd + st) % 60;
	int ma = (md + mt) % 60 + (sd + st) - sa;
	int ha = (hd + ht) % 24;

	printf("Heure d'arrivée: %d:%d:%d", ha, ma, sa);
}