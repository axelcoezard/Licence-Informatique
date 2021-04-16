#include <stdio.h>
#include <stdlib.h>

#include "vigenere.h"

#define ASCII_SIZE 128

int ft_strlen(const char *s);
int ft_iscntrl(int c);
int ft_isascii(int c);
int ft_isprint(int c);

int main(int argc, char **argv)
{
    char *msg = cypher("Ceci est un rappel sur le chiffre de Vigenere", "lundi");
    // char *msg = cypher("LOL, t'as bien galere pour dechiffrer ce message qui sert a rien! :P", "lundi");
    printf("%s\n", msg);
    char *demsg = decypher(msg, "lundi");
    printf("%s\n", demsg);
}

char *generic_cypher(char *message, char *key, int way)
{
    int len_message = ft_strlen(message);
    int len_key = ft_strlen(key);
    char *cypher = malloc(len_message * sizeof(char));

    int i = 0;
    while (i < len_message)
    {
        char c = message[i];
        cypher[i] = c + key[i % len_key] * way % ASCII_SIZE;
        i++;
    }

    return cypher;
}

char *cypher(char *message, char *key)
{
    return generic_cypher(message, key, 1);
}

char *decypher(char *message, char *key)
{
    return generic_cypher(message, key, -1);
}

char *analysis(char *message)
{
    // TO-DO: Trouver la longueur de la clef.
    // TO-DO: Trouver la clef.
}

int ft_strlen(const char *s)
{
    int len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

int ft_iscntrl(int c)
{
    return (c >= 0 && c <= 31) || c == 127;
}

int ft_isascii(int c)
{
    return c >= 0 && c <= 127;
}

int ft_isprint(int c)
{
    return ft_isascii(c) && !ft_iscntrl(c);
}