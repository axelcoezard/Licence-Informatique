#include <stdio.h>

int estDansRectangle(int x1, int y1, int x2, int y2, int x, int y);

int estDansUnion(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22, int x, int y);
int estDansInter(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22, int x, int y);
int estDansUnSeul(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22, int x, int y);
int estContenusDans(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22);
int sontDisjoints(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22);
int sontSecants(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22);

int main()
{
}

int estDansRectangle(int x1, int y1, int x2, int y2, int x, int y)
{
	return x >= x1 && y <= y1 && x <= x2 && x >= y2;
}

int estDansUnion(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22, int x, int y)
{
	return estDansRectangle(x11, y11, x12, y12, x, y) && estDansRectangle(x21, y21, x22, y22, x, y);
}

int estDansInter(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22, int x, int y)
{
	/* TO-DO */
}

int estDansUnSeul(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22, int x, int y)
{
	return estDansRectangle(x11, y11, x12, y12, x, y) || estDansRectangle(x21, y21, x22, y22, x, y);
}

int estContenusDans(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22)
{
	return (x11 >= x21 && y11 <= y21 && x12 <= x22 && y12 >= y22);
}

int sontDisjoints(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22)
{
	return !estContenusDans(x11, y11, x12, y12, x21, y21, x22, y22) && !sontSecants(x11, y11, x12, y12, x21, y21, x22, y22);
}

int sontSecants(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22)
{
	/* TO-DO */
}