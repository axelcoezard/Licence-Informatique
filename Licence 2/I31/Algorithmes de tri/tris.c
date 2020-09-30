#include <stdio.h>

void tri_selection(int *tab, int n);
void tri_insertion(int *tab, int n);
void tri_fusion(int *tab, int n);

int main()
{
    int tab[] = {1, 5, 8, 3, 9, 7};
    tri_insertion(tab, 6);
    for (int i = 0; i < 6; i++)
        printf("%d\n", tab[i]);
}

void tri_selection(int *tab, int n)
{
    int i, j, petit, i_petit;
    int tmp;
    for (i = 0; i < n - 1; i++)
    {
        i_petit = i;
        petit = tab[i];
        for (j = i; j < n; j++)
        {
            if (tab[j] < petit)
            {
                petit = tab[j];
                i_petit = j;
            }
        }
        tmp = tab[i_petit];
        tab[i_petit] = tab[i];
        tab[i] = tmp;
    }
}

void tri_insertion(int *tab, int n)
{
    int i, j, tmp;
    for (i = 0; i < n; i++)
    {
        j = i;
        while (j > 0 && tab[j] < tab[j - 1])
        {
            tmp = tab[j - 1];
            tab[j - 1] = tab[j];
            tab[j] = tmp;
            j--;
        }
    }
}