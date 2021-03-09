#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ex_1.h"

int main() {
    tbool result1 = EstPalindrome("hannah");
    tbool result2 = EstPalindrome("axel");

    printf("hannah est un palindrome: %s\n", result1 ? "Oui" : "Non");
    printf("axel est un palindrome: %s\n", result2 ? "Oui" : "Non");
}

tbool EstPalindrome(char *phrase) {
    int taille = strlen(phrase);
    int i = 0;
    while(i < taille) {
        if(phrase[i] != phrase[taille - i - 1]) 
            return FALSE;
        i++;
    }
    return TRUE;
}

