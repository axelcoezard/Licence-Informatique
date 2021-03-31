#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

char *table_to_string(int *table, int size);
int *string_to_table(char *string);

int main(int argc, char **argv)
{
    int longueur = argv[1][0] - '0';

    int tube1[2], tube2[2], tube3[2];
    pipe(tube1);
    pipe(tube2);
    pipe(tube3);

    if (fork() == 0)
    {
        srand(time(NULL));
        int i = 0;
        while (i < longueur)
        {
            char message[10] = "";
            sprintf(message, "%d", rand() % 1000);
            write(tube1[1], message, 10);
            close(tube1[0]);
            close(tube1[1]);
            printf("Envoyé: %s\n", message);
            i++;
        }
        exit(EXIT_SUCCESS);
    }

    if (fork() == 0)
    {
        const int C = 3;
        // Lecture d'un nombre sur le Tube 1
        close(tube1[1]);
        char message[10] = "";
        read(tube1[0], message, 10);
        int nombre = atoi(message);
        close(tube1[0]);
        // Ajout de la constante C
        printf("Reçu: %d\n", nombre);
        nombre += C;
        // Envoie le nombre sur le Tube 2
        // sprintf(message, "%d", nombre);
        // write(tube2[1], message, 10);
        // close(tube2[0]);
        // close(tube2[1]);
        // exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}