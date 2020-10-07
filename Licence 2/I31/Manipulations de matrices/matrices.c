#include <stdio.h>

void add_matrix();
void mul_matrix(int *a, int *b, int *c, int l, int col);

int main()
{
}

void mul_matrix(int *a, int *b, int *c, int lig, int col)
{
	int i, j, k;
	for (i = 0; i < lig; i++)
	{
		for (j = 0; j < col; j++)
		{
			c[i * col + j] = 0;
			for (k = 0; k < col; k++)
			{
				c[i * col + j] += a[i * col + k] * b[k * lig + j];
			}
		}
	}
}
