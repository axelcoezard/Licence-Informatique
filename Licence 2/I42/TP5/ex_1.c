#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
 
int main(void) {
    int i;

    printf("Je suis seul\n");
    for (i = 10; i > 0; i--) {
        printf("%d ", i);
        fflush(stdout);
        sleep(1);
    }
    printf("\n Nous sommes deux maintenant\n");
    fork();
    while(1);
}
