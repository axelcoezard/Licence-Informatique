#include <stdio.h>
#include <stdlib.h>
#include "ex_1.h"

int main() {
    ullong R = Factorielle(20);
    printf("%lld\n", R);
}

/**
 * \brief Calcule n factorielle
 * \param n Un entier non-signé
 * \return 1 * 2 * ... * n
 */
ullong Factorielle(uchar n) {
    ullong i = 1;
    while (n > 1) {
        i *= n;
        n--;
    }
    return i;
}