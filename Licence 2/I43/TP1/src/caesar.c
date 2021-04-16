#include <stdio.h>
#include <stdlib.h>

#include "caesar.h"

#define ASCII_SIZE 128

int ft_strlen(const char *s);
int ft_iscntrl(int c);
int ft_isascii(int c);
int ft_isprint(int c);

int main(int argc, char **argv)
{
    char *msg = cypher("LOL, t'as bien galere pour dechiffrer ce message qui sert a rien! :P", 11);
    printf("%s\n", msg);
    char *demsg = decypher(msg, 11);
    printf("%s\n", demsg);
}

char *cypher(char *message, char key)
{
    int len = ft_strlen(message), i = 0;
    char *cypher = malloc(len * sizeof(char));

    while (i < len)
    {
        char c = message[i];
        if (ft_isprint(c))
            cypher[i] = c + key % ASCII_SIZE;
        else
            cypher[i] = c;
        i++;
    }

    return cypher;
}

char *decypher(char *message, char key)
{
    return cypher(message, -key);
}

int analysis(char *message)
{
    int *counts = malloc(ASCII_SIZE * sizeof(int));
    int len = ft_strlen(message), i = 0, j = 0;
    while (i < ASCII_SIZE)
        counts[i++] = 0;
    char max = 0;
    while (j < len)
    {
        char letter = message[j];
        counts[letter]++;
        if (ft_isprint(letter) && counts[max] < counts[letter])
            max = letter;
        j++;
    }
    free(counts);
    return 'e' - max;
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