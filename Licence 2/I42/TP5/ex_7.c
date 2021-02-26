#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

typedef char* string;

int main() {
    string commandes[3] = {
        "who", "ls" ,"pwd"
    };

    for(int i = 0; i < 3; i++) {
        if (fork() == 0) {
            execlp(commandes[i], commandes[i], NULL);
        }
        wait(1);
        sleep(2);
    }    
}