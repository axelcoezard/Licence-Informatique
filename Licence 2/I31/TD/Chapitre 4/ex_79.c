#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int aleat(int R);

int main()
{
	int R;
	printf("Entrer un nombre R: ");
	scanf("%d", &R);
	printf("Aleat(%d)=%d\n", R, aleat(R));
}

int aleat(int R)
{
	srand(time(NULL));
	float r = (float)rand() / 1000000000 - 1;
	r = r < 0 ? -r : r;
	return (r * R) + 1;
}