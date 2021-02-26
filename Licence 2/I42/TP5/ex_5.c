#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void SIGUSR1_recu();
int signal_recu = 0;

int main() {
    int p_pid = getpid();
    if (fork() == 0 ) { // le programme se duplique.
        int f_pid = getpid();
        signal(SIGUSR1, SIGUSR1_recu);
        while(!signal_recu) {
            printf("(%i) En attente d'un signal SIGUSR1...\n", f_pid);
            sleep(10);  
            kill(p_pid, SIGTERM);
            printf("(%i) tue le père (%i)\n", f_pid, p_pid);
        }
    } else {
        while(1); // le père exécute une boucle infinie.
    }
}

void SIGUSR1_recu() {
    signal_recu = 1;
}