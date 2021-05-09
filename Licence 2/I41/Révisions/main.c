#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#include "main.h"

t_list Fusionner(t_list A, t_list B)
{
	t_list list;
	int i;
	int j;
	int k;

	list.length = A.length + B.length;

	i = 0;
	j = 0;
	k = 0;
	while (i + j < list.length)
	{
		k++;
		if (A.values[i] < B.values[j])
			list.values[k] = A.values[i++];
		else
			list.values[k] = B.values[j++];
	}
	return list;
}

t_list Trouver(char *A, char *B)
{
	int i;
	int j;
	int Asize;
	t_list pos;

	Asize = strlen(A);
	pos.length = 0;
	i = 0;
	j = 0;
	while (B[j] != '\0')
	{
		if (B[j] == A[i])
			i++;
		else
			i = 0;
		if (i == Asize - 1)
		{
			pos.values[pos.length++] = j;
			i = 0;
		}
		j++;
	}
	return pos;
}

void main_Blocs()
{
	int *integers;
	char *concat;
	int i;

	integers = malloc(4 * sizeof(int));
	integers[0] = 3;
	integers[1] = 0;
	integers[2] = 8;
	integers[3] = 2;

	concat = Blocs(integers, 4, 8);
	i = 0;
	while (i < 4 * 8)
	{
		write(0, &(concat[i]), sizeof(char));
		i++;
	}
	free(concat);
	free(integers);
}

char *S2B(int N, int t)
{
	char *binary;
	int i;

	binary = malloc((t) * sizeof(char));
	i = 0;
	while (i < t)
	{
		binary[t - i - 1] = N % 2 + '0';
		N /= 2;
		i++;
	}
	return binary;
}

char *Blocs(int *L, int L_size, int t)
{
	char *binary;
	char *concat;
	int i;
	int j;

	concat = malloc(L_size * t * sizeof(char));
	i = 0;
	while (i < L_size)
	{
		binary = S2B(L[i], t);
		j = 0;
		while (j < t)
		{
			concat[j + i * t] = binary[j];
			j++;
		}
		free(binary);
		i++;
	}
	return concat;
}

void main_DansUnite()
{
	float x;
	float y;

	x = 0.5;
	y = 0.3;
	printf("Est dans Unité? %s", DansUnite(x, y) ? "Oui" : "Non");
}

int DansUnite(float x, float y)
{
	return x * x + y * y < 1;
}

void main_Flechette()
{
	float *vector;

	vector = Flechette();
	printf("Point: (%f, %f)\n", vector[0], vector[1]);
	free(vector);
}

float *Flechette()
{
	struct timespec spec;
	float *vector;

	vector = malloc(2 * sizeof(float));
	clock_gettime(0, &spec);
	srand(spec.tv_nsec);
	vector[0] = (float)(rand() % 100) / 100.0;
	vector[1] = (float)(rand() % 100) / 100.0;
	return vector;
}

int main_Cribler(int argc, char **argv)
{
	int n;
	int count;

	if (argc < 2)
		return 0;

	n = atoi(argv[1]);
	printf("n= %d\n", n);
	count = Cribler(n);
	printf("count= %d\n", count);
	printf("count(modif)= %d\n", 4 * count / n);
}

int Cribler(int n)
{
	int i;
	float *vect;
	int count;

	count = 0;
	i = 0;
	while (i < n)
	{
		vect = Flechette();
		count += DansUnite(vect[0], vect[1]);
		free(vect);
		i++;
	}
	return count;
}
