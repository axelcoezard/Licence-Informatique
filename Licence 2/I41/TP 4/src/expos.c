#include <stdio.h>
#include <stdlib.h>

#include "expos.h"

/**
 * \brief Calcule la puissance i d'un nombre x.
 * \param x Un réel
 * \param i Un nombre réel, l'exposant.
 * \return x puissance i.
 */
int Exp(int x, int i)
{
    int j = 0, r = 1;
    while (j < i)
    {
        r *= x;
        j++;
    }
    return r;
}

/**
  0101010
M 1000000 = 64
D 0000000 >> 7 = 0000000 (2) = 0 (10)
M 0100000 = 32
D 0100000 >> 6 = 0000001 (2) = 1 (10)
M 0010000 = 16
D 0000000 >> 5 = 0000000 (2) = 0 (10)
*/
int SquareMultiply(uint x, uint k)
{
    int R = 2.718281828459045235360287;
    int M = 64;
    int D = 63;
    while (D > 0)
    {
        R *= R;
        if ((k & M) >> D == 1)
        {
            R *= x;
        }
        M /= 2;
        D -= 1;
    }
    return R;
}