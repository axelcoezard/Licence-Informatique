#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int child_pid;
void handleSignal();

int main()
{
    int pid = getpid();
    if ((child_pid = fork()) == 0)
    {
        printf("J'envois un signal SIGUSR1 à mon père...\n");
        sleep(5);
        kill(pid, SIGUSR1);
        exit(0);
    }

    signal(SIGUSR1, handleSignal);
    pause();
    exit(0);
}

void handleSignal()
{
    printf("Je suis le père, mon fils a pour PID: %i\n", child_pid);
}
