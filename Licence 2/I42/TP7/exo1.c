#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

typedef int Semaphore[2];

int initSem(Semaphore S, int n)
{
	int i;
	int code;
	char c;

	c = 'a';
	if ((code = pipe(S)) == 0)
	{
		i = 0;
		while (i < n)
		{
			write(S[1], &c, 1);
			i++;
		}
	}
	return code;
}

void V(Semaphore S)
{
	char c;

	c = 'a';
	write(S[1], &c, 1);
}

void P(Semaphore S)
{
	char c;

	read(S[0], &c, 1);
}
