#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>


int main(int argc, char *argv[]) {
  int NP = 2; // nombre de joueurs
  int NT = 5; // nombre de tours
  int i;

  int* decisions = malloc(NP * sizeof(int));
  int* scores = malloc(NP * sizeof(int));
  int resultat = 0;

  i = 0;
  while (i < NP) {
    if (fork() == 0) {
      // Tirer au hazard la décision de continuer
      srand(time(NULL));
      decisions[i] = rand() % 2;

      // TO-DO: Agir en fonction du résultat
      // TO-DO: lire le score et l'afficher
      exit(EXIT_SUCCESS);
    }
    i++;
  }

  free(decisions);
  free(scores);
  exit(EXIT_SUCCESS);
}
