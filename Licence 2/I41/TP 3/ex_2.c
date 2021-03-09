#include <stdio.h>

#include "ex_2.h"

int main() {
    int liste[5] = {7, 1, 6, 2, 3};
    TriSelection(liste, 5);

    for(int i = 0; i < 5; i++) {
        printf("%i \n", liste[i]);
    }
}

void TriSelection(int *liste, ushort n) {
    int ptr = 0;
    while (ptr < n) {
        int min = liste[ptr];
        int i = ptr;
        while(i < n) {
            if(liste[i] < min) 
                min = liste[i];
            i++;
        }
        int tmp = liste[ptr];
        liste[ptr] = liste[i];
        liste[i] = tmp;
        ptr++;
    }
}