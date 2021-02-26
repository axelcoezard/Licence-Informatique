#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int n = 0;
    if (fork() == 0) {
        n++;
        printf("Je suis le fils, n=%i\n", n);
    } else {
        n++;
        printf("Je suis le père, n=%i\n", n);
    }
}