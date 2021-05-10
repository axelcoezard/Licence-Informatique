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


int main(int argc, char *argv[])
{
	int nbFils;    // nombre de processus fils, passé en paramètre
	char *Nomfic;  // nom du fichier passé en paramètre
	int i;
	int iMax;
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

	iMax = 0;

	for (i = 1; i <= nbFils; i++) { // BOUCLE DE CREATION SEQUENTIELLE DES nbFils (maximum)
		int tube[2];
		pipe(tube);
		// Traitement des fils
		if (fork() == 0) {
			strncpy(chaine, tabPI, i);
			printf("Fils %i cherche %s dans fichier\n", i, chaine);

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

			write(tube[1], &count, sizeof(int)); // Il envoit son le nombre d'occurrence
			close(tube[0]);
			close(tube[1]);
			exit(EXIT_SUCCESS);
		}

		// Traitement du père

		close(tube[1]);
		read(tube[0], &count, sizeof(int));
		close(tube[0]);

		printf("PERE : Reponse du %d ieme grep: %d\n", i, count);

		// J'arrête la recherche si l'un des enfant ne trouve rien.
		if (count < 1) break;

		// Je regénère la chaine correspondante a la longueur i,
		// car elle a été remplacée par celle de la longueur i + 1.
		strncpy(chaine, tabPI, i);
		iMax = i;
	}

	// A compléter
	printf("PERE : fils numero %d a trouve la plus longue chaine pour PI, soit : %s\n", iMax , chaine);


}
