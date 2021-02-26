#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

typedef char* string;

int main() {
    string commandes[2] = {
        "titi", "pwd"
    };

    for(int i = 0; i < 2; i++) {
        if (fork() == 0) {
            execlp(commandes[i], commandes[i], NULL);
            exit();
        }
        wait(1);
        sleep(2);
    }    
}