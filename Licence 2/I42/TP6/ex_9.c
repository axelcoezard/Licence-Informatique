#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

uint *generate_tab(uint n);

int main()
{
    int n = 6;

    // Génère deux vecteurs v1 et v2 aléatoires.
    uint *V1 = generate_tab(n);
    uint *V2 = generate_tab(n);

    // Somme des travaux des processus
    int somme = 0;

    int i = 0;
    while (i < n)
    {
        // Créé un tube
        int tube[2];
        pipe(tube);
        // Créé un processus enfant
        if (fork() == 0)
        {
            int n_pid = getpid();
            // Calcule v1[i] * v2[i].
            uint value = V1[i] * V2[i];
            // Converti le value en chaine de caractère.
            char message[10] = "";
            sprintf(message, "%d", value);
            // Ecriture dans la value dans le pipe
            write(tube[1], message, 10);
            close(tube[0]);
            close(tube[1]);
            // Affichage du travail du processus
            printf("Processus %i a calcule\t%i x\t%i =\t%i\n", i, V1[i], V2[i], value);
            exit(EXIT_SUCCESS);
        }

        close(tube[1]);
        // Lecture du message dans le tube
        char message[10] = "";
        read(tube[0], message, 10);
        // Ajout de la valeur à la somme
        somme += atoi(message);
        close(tube[0]);
        i++;
    }

    // Affichage du résultat du produit scalaire
    printf("Résultat: %d\n", somme);

    return EXIT_SUCCESS;
}

uint *generate_tab(uint n)
{
    uint *tab = malloc(n * sizeof(uint));
    uint i = 0;
    struct timespec spec;

    clock_gettime(0, &spec);
    srand(spec.tv_nsec);
    printf("Vecteur: ");
    while (i < n)
    {
        tab[i] = rand() % 10;
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");

    return tab;
}
