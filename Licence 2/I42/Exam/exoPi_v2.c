#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

// Le père génère SEQUENTIELLEMENT N fils (N est passé en paramètre du programme).
// Chaque fils va chercher grâce à la commande grep -c) dans un fichier, donné
// en paramètre, une séquence de plus en plus longue des chiffres composant le
// nombre PI : le 1er fils cherchera la chaine "3" dans le fichier, le 2ème
// cherchera la chaine "31" dans le fichier, le 3ème cherchera la chaine "314", etc...
// Le père récupèrera, grâce au tube, le résultat de cette recherche puis il affichera
// le numéro du fils (entre 1 et N) qui a trouvé la plus longue chaine.

typedef struct {
	int pid;
	int i;
	int count;
} t_Infos;


int main(int argc, char *argv[])
{
	int nbFils;    // nombre de processus fils, passé en paramètre
	char *Nomfic;  // nom du fichier passé en paramètre
	int i;
	t_Infos infosMax;
	int count;
	FILE *file; // pour remplacer le grep que je ne sais plus faire.

	// tableau de caractères permettant d'avoir les 1ères décimales de PI
	char tabPI[]="3141592653589793238462643383279502884197169399375";
	// tableau de caractères nécessaire pour construire une chaine de i
	// caractères à partir de tabPI en utilisant la fonction strncpy
    // ATTENTION : strncpy ne recopie pas le caractère de fin de chaine \0
	char chaine[100];


	if (argc < 3) { perror("nbre d'arg insuffisant : Nbfils  fichier\n"); exit(1); }

	// à compléter

	nbFils = atoi(argv[1]);   // nbre de proc fils à générer
	Nomfic = argv[2];	 // nom du fichier à traiter

	for (i = 1; i <= nbFils; i++) { // BOUCLE DE CREATION SEQUENTIELLE DES nbFils (maximum)
		int tube[2];
		pipe(tube);
		// Traitement des fils
		if (fork() == 0) {
			strncpy(chaine, tabPI, i);

			int petitTube[2];
			pipe(petitTube);

			// Création du processus petit_fils.
			if (fork () == 0) {
				int ppid = getppid();
				int pid = getpid();
				printf("Petit Fils %d de pid %d (de père %d) cherche %s dans fichier\n", i, pid, ppid, chaine);
				// Grep -c fait maison parce que je ne sais plus comment
				// faire le grep en C...
				count = 0;
				file = fopen(Nomfic, "r+");
				if (file != NULL) {
					char c;
					int j = 0;
					while ((c = fgetc(file)) != EOF) {
						if (c == chaine[j]) j++;
						else j = 0;
						if (j == i - 1) {
							count++;
							j = 0;
						}
					}
					fclose(file);
				}
				// Il envoit son le nombre d'occurrence
				write(petitTube[1], &count, sizeof(int));
				close(petitTube[0]);
				close(petitTube[1]);
				exit(EXIT_SUCCESS);
			}

			close(petitTube[1]);
			read(petitTube[0], &count, sizeof(int));
			close(petitTube[0]);

			// On stocke les infos dans la structure
			t_Infos infos;
			infos.i = i;
			infos.pid = getpid();
			infos.count = count;

			printf("FILS %d de pid %d: Réponse pour %i eme grep: %d\n", i, infos.pid, i, count);

			write(tube[1], &infos, sizeof(t_Infos)); // Il envoit son le nombre d'occurrence
			close(tube[0]);
			close(tube[1]);
			exit(EXIT_SUCCESS);
		}

		// Traitement du père

		t_Infos infos;
		close(tube[1]);
		read(tube[0], &infos, sizeof(t_Infos));
		close(tube[0]);

		printf("PERE : Reponse lue : fils %d (de pid %d) resultat grep: %d\n", infos.i, infos.pid, infos.count);

		// J'arrête la recherche si l'un des enfant ne trouve rien.
		if (infos.count < 1) break;

		// Je regénère la chaine correspondante a la longueur i,
		// car elle a été remplacée par celle de la longueur i + 1.
		strncpy(chaine, tabPI, infos.i);
		infosMax = infos;
	}

	// A compléter
	printf(
		"PERE : fils numero %d (de pid %d) a trouve la plus longue chaine pour PI, soit : %s\n",
		infosMax.i,
		infosMax.pid,
		chaine
	);
}
