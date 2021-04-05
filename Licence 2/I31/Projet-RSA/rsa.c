#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gmp.h>

typedef struct
{
    mpz_t v; // Valeur mpz_t du nombre
} Bignum;

typedef struct
{
    Bignum pub; // Cléf publique
    Bignum pri; // Cléf privée
} KeyHolder;

int generate_seed();

Bignum generate_prime(int n);
Bignum generate_indicator(Bignum p, Bignum q);
Bignum generate_public_key(Bignum phi_n, int size);
Bignum generate_private_key(Bignum e, Bignum phi_n);

KeyHolder generate_parameters(int lp, int lq);

Bignum cypher_message(Bignum message, int size, Bignum pri_key);
Bignum decypher_message(Bignum cypher, int size, Bignum pub_key);

int hash(Bignum message, int k);
Bignum signature(Bignum message, int k, Bignum pri_key);

const char *read_file(char *filename);

/**
 * 
 */
int main()
{
    // Demande à l’utilisateur la taille k en bits des signatures à produire.
    int k;
    printf("Entrer un nombre k de bits >= 3 pour les signatures RSA.\nk=");
    scanf("%d", &k);

    // Génère les paramètres pour l’algorithme de chiffrement RSA.
    int lp, lq;
    if (k % 2 == 0)
        lp = lq = k / 2;
    else
    {
        lp = (k - 1) / 2;
        lq = lp + 1;
    }

    // Récupère le portecléf composé d'une cléf privée
    // et d'une cléf publique.
    KeyHolder keys = generate_parameters(lp, lq);

    printf("* Ouverture du fichier 'fichier.txt'..\n");
    char *text = read_file("fichier.txt");
    printf("* Message à signer: %s\n\n", text);

    // Stock un message en base 128 dans un bignum en base 10.
    Bignum message;
    printf("* Conversion du message...\n");
    mpz_init_set_str(message.v, text, 128);
    gmp_printf("=> Message converti: %Zd\n\n", message.v);

    gmp_printf("* Signature du message...\n");
    Bignum s = signature(message, k, keys.pri);
    gmp_printf("=> Signature: %Zd\n\n", s.v);
}

/**
 * Récupère l'heure actuelle en nanosecondes.
 */
int generate_seed()
{
    struct timespec spec;
    clock_gettime(0, &spec);

    return spec.tv_nsec;
}

/**
 * Génère un nombre aléatoire premier de taille n bits,
 * en utilisant une graine. La graine correspond 
 * aux nanosecondes actuelles.
 */
Bignum generate_prime(int n)
{
    Bignum prime;
    gmp_randstate_t r;

    int seed = generate_seed();
    mpz_init(prime.v);
    gmp_randinit_default(r);
    gmp_randseed_ui(r, seed);

    do
    {
        mpz_urandomb(prime.v, r, n);
        mpz_setbit(prime.v, n - 1);
        mpz_nextprime(prime.v, prime.v);
    } while (mpz_sizeinbase(prime.v, 2) != n);

    gmp_randclear(r);

    return prime;
}

/**
 * 
 */
Bignum generate_indicator(Bignum p, Bignum q)
{
    Bignum phi_n, p_1, q_1, one;
    mpz_init(phi_n.v);
    mpz_init(p_1.v);
    mpz_init(q_1.v);
    mpz_init_set_ui(one.v, 1);

    mpz_sub(p_1.v, p.v, one.v);
    mpz_sub(q_1.v, q.v, one.v);
    mpz_mul(phi_n.v, p_1.v, q_1.v);

    mpz_clear(p_1.v);
    mpz_clear(q_1.v);
    mpz_clear(one.v);

    return phi_n;
}

/**
 * 
 */
Bignum generate_public_key(Bignum phi_n, int size)
{
    Bignum e, e_mod_phi, pgcd;
    gmp_randstate_t r;

    int seed = generate_seed();
    mpz_init(e.v);
    mpz_init(e_mod_phi.v);
    mpz_init(pgcd.v);
    gmp_randinit_default(r);
    gmp_randseed_ui(r, seed);

    do
    {
        mpz_urandomb(e.v, r, size);
        mpz_mod(e_mod_phi.v, e.v, phi_n.v);
        mpz_gcd(pgcd.v, phi_n.v, e.v);
    } while (mpz_cmp(e_mod_phi.v, phi_n.v) >= 0 || mpz_get_si(pgcd.v) != 1);

    mpz_clear(e_mod_phi.v);
    mpz_clear(pgcd.v);
    gmp_randclear(r);

    return e;
}

/**
 * 
 */
Bignum generate_private_key(Bignum e, Bignum phi_n)
{
    Bignum d;

    mpz_init(d.v);
    mpz_invert(d.v, e.v, phi_n.v);

    return d;
}

/**
 * 
 */
KeyHolder generate_parameters(int lp, int lq)
{
    int n = lp + lq;

    printf("* Génération des modules de chiffrement p et q...\n");
    Bignum p = generate_prime(n);
    Bignum q = generate_prime(n);
    gmp_printf("1. p: %Zd\n2. q: %Zd\n\n", p.v, q.v);

    printf("* Génération de l'indicatrice d'Euler phi(n)...\n");
    Bignum phi_n = generate_indicator(p, q);
    gmp_printf("=> phi(n): %Zd\n\n", phi_n.v);

    printf("* Génération de la clef publique et privée...\n");
    KeyHolder keys;
    keys.pub = generate_public_key(phi_n, n);         // e
    keys.pri = generate_private_key(keys.pub, phi_n); // d

    gmp_printf("1. Cléf publique: %Zd\n", keys.pub.v);
    gmp_printf("2. Cléf privée: %Zd\n\n", keys.pri.v);

    return keys;
}

/**
 * 
 */
Bignum cypher_message(Bignum message, int size, Bignum pub_key)
{
    Bignum c, n;

    mpz_init(c.v);
    mpz_init(n.v);
    mpz_set_ui(n.v, size);
    mpz_powm(c.v, message.v, pub_key.v, n.v); // message ^ pub_key (mod n)
    mpz_clear(n.v);

    return c;
}

/**
 * 
 */
Bignum decypher_message(Bignum cypher, int size, Bignum pri_key)
{
    Bignum c, n;

    mpz_init(c.v);
    mpz_init(n.v);
    mpz_set_ui(n.v, size);
    mpz_powm(c.v, cypher.v, pri_key.v, n.v); // chiffré ^ priv_key (mod n)
    mpz_clear(n.v);

    return c;
}

/**
 * Hash le message sur k caractères.
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
    return 0;
}

/**
 * Signe le contenu d'un fichier à partir
 * de la clef privée.
 */
Bignum signature(Bignum message, int k, Bignum pri_key)
{
    Bignum c;
    mpz_init_set_ui(c.v, hash(message, k - 1));
    return decypher_message(c, k, pri_key);
}

/**
 * Ouvre le fichier "filename" et lit
 * la première ligne.
 */
const char *read_file(char *filename)
{
    FILE *file = fopen("./fichier.txt", "r+");
    char *text = (char *)malloc(1000);

    if (file != NULL)
    {
        fgets(text, 1000, file);
        fclose(file);
    }
    return text;
}
