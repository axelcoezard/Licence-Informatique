#include <stdio.h>
#include <time.h>
#include <string.h>
#include <gmp.h>

typedef struct
{
    mpz_t v; // Valeur mpz_t du nombre
} Bignum;

int main()
{
    Bignum message;
    mpz_init_set_str(message.v, "4a570ba940bf26210926057703417df32874c857872d4cae532af37a8bcd959", 16);

    hash(message, 14);
}

/**
 * Fonction de hachage MD9
 * Elle permet de générer l'empreinte d'un message
 */
int hash(Bignum message, int k)
{
    Bignum hash;
    mpz_init_set_ui(hash.v, 0);

    int digits;
    // Récupère le nombre de chiffres du message
    // et ajotue des zero jusqu'a ce qu'il soit multiple de k.
    while ((digits = mpz_sizeinbase(message.v, 10)) % k != 0)
        mpz_mul_ui(message.v, message.v, 10);
    int limbs = digits / k; // Nombre de blocs de k bits
    /**
     * TODO: Split le messsage en digits/k blocs de k bits
     * TODO: XORer digts/k blocs de k bits. 
     */
}