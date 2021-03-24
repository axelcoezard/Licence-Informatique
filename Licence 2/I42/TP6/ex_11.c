#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

/**
 * \brief Calcul le nombre d'occurence d'un mot dans plusieurs fichiers.
 */
int main (int argc, char **argv) {
    // Récupération du mot cherché
    char *chaine = argv[1];
    int t_chaine = strlen(chaine);
    // Récupuréation du nombre de fichiers
    int files_count = argc - 2;
    // Total d'occurence du mot cherché
    int totalCount = 0;
    while (files_count > 0) {
        // Créé un tube
        int tube[2];
        pipe(tube);
        // Récupère la valeur de l'argument courant.
        char* file_name = argv[1 + files_count];
        // Créé un processus enfant.
        if (fork() == 0) {
            // Nombre d'occurence du mot dans un fichier
            int count = 0;
            // Ouverture du fichier
            FILE *file = fopen(file_name, "r+");    
            if (file != NULL) {
                char c;
                int i = 0;
                // Lecture caractère par caractère du contenu
                // du fichier et comptage du nombre d'occurences
                // du mot cherché.
                while ((c = fgetc(file)) != EOF) {
                    if (c == chaine[i]) i++;
                    else i = 0;
                    if (i == t_chaine - 1) {
                        count++;
                        i = 0;
                    }
                }
                // Arrête la lecture du fichier
                fclose(file);
            }
            // Converti le value en chaine de caractère.
            char message[10] = "";
            sprintf(message, "%d", count);
            // Ecriture dans la value dans le pipe
            write(tube[1], message, 10);
            close(tube[0]);
            close(tube[1]);
            exit(EXIT_SUCCESS);
        }
        close(tube[1]);
        // Lecture du message dans le tube
        char message[10] = "";
        read(tube[0], message, 10);
        // Ajout du nombre d'occurences locales au total.
        totalCount += atoi(message);
        close(tube[0]);
        files_count--;
    }
    // Affiche le nombre d'occurence du mot cherché.
    printf(
        "Le mot %s a été trouvé %d fois dans %d fichiers différents.\n", 
        chaine, totalCount, argc - 2
    );
}