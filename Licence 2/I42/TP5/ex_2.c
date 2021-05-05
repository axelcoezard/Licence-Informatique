#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 *  
 */
int main()
{
    int p_pid = getpid();
    int c_pid;

    p_pid = getpid();
    if ((c_pid = fork()) == 0)
    {
        printf("Je suis le fils, mon père a pour PID:  %i\n", p_pid);
        exit(0);
    }
    printf("Le PID du père est: %i\n", p_pid);
    printf("Je suis le père, mon fils a pour PID:  %i\n", c_pid);
    exit(0);
}