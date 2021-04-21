#include <stdio.h>
#include <math.h>

#include "main.h"

float
    encrypt[3][1],
    decrypt[3][1],
    a[3][3],
    b[3][3],
    mes[3][1],
    c[3][3];

void main()
{
    getKeyMessage();
    cypher();
    decypher();
}

void cypher()
{
    int i;
    int j;
    int k;

    i = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 1)
        {
            k = 0;
            while (k < 3)
            {
                encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];
                k++;
            }
            j++;
        }
        i++;
    }

    printf("Message encrypté: ");
    i = 0;
    while (i < 3)
    {
        printf("%c", (char)(fmod(encrypt[i][0], 26) + 'a'));
        i++;
    }
    printf("\n");
}

void decypher()
{
    int i;
    int j;
    int k;

    inverse();

    i = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 1)
        {
            k = 0;
            while (k < 3)
            {
                decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
                k++;
            }
            j++;
        }
        i++;
    }

    printf("Message décrypté: ");
    i = 0;
    while (i < 3)
    {
        printf("%c", (char)(fmod(decrypt[i][0], 26) + 'a'));
        i++;
    }
    printf("\n");
}

void getKeyMessage()
{
    int i;
    int j;
    char msg[3];

    printf("Entrer une matrice inversible de taille 3x3:\n");
    i = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            scanf("%f ", &a[i][j]);
            c[i][j] = a[i][j];
            j++;
        }
        i++;
    }

    printf("\nEntrer un message de 3 caractères: ");
    scanf("%s ", msg);

    i = 0;
    while (i < 3)
    {
        mes[i][0] = msg[i] - 'a';
        i++;
    }
}

void inverse()
{
    /**
    * \todo Inverser la matricebw<a 
    */
}
