#include <stdio.h>
#include <signal.h>
 
void traitersignal(int sig) {
   printf("Signal %d bien recu\n", sig);
}
 
int main(void) {
   signal(SIGUSR1, traitersignal);
   while(1);
}