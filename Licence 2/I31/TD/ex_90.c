#include <stdio.h>

int estDansRectangle(int x1, int y1, int x2, int y2, int x, int y);
int estSurContour(int x1, int y1, int x2, int y2, int x, int y);
int estExterieur(int x1, int y1, int x2, int y2, int x, int y);
int estInterieur(int x1, int y1, int x2, int y2, int x, int y);

int main()
{
}

int estDansRectangle(int x1, int y1, int x2, int y2, int x, int y)
{
	return x > x1 && y < y1 && x < x2 && x > y2;
}

int estSurContour(int x1, int y1, int x2, int y2, int x, int y)
{
	return (x >= x1 && x <= x2 && y == y2) ||
				 (x >= x1 && x <= x2 && y == y1) || (x == x1 && y >= y2 && y <= y1) || (x == x2 && y >= y2 && y <= y1);
}

int estExterieur(int x1, int y1, int x2, int y2, int x, int y)
{
	return !estDansRectangle(x1, y1, x2, y2, x, y) && !estSurContour(x1, y1, x2, y2, x, y);
}

int estInterieur(int x1, int y1, int x2, int y2, int x, int y)
{
	return estDansRectangle(x1, y1, x2, y2, x, y) && estSurContour(x1, y1, x2, y2, x, y);
}