#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

/**
 *  
 */
int main(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (fork() == 0)
        {
            execlp(argv[i], argv[i], NULL);
            exit(0);
        }
        wait(0);
        i++;
    }
    exit(0);
}