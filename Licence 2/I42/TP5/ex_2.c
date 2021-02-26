#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int p_pid = getpid();
    printf("Le pid est: %i\n", p_pid);

    int c_pid;
    if ((c_pid = fork()) == 0) {
        printf("Je suis le fils, mon père a pour PID:  %i\n", p_pid);
    } else {
        printf("Je suis le père, mon fils a pour PID:  %i\n", c_pid);
    }
}