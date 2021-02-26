#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int fils_pid;
void affiche_fils_pid();

int main() {
    int pere_pid = getpid();
    if((fils_pid = fork()) == 0) {
        printf("J'envois un signal SIGUSR1 à mon père:\n");
        sleep(5);   
        kill(pere_pid, SIGUSR1);
    } else {
        signal(SIGUSR1, affiche_fils_pid);
    }
    while(1);
}

void affiche_fils_pid() {
    printf("Je suis le père, mon fils a pour PID: %i\n", fils_pid);
}

