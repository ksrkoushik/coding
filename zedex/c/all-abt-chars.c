#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ch = 'A';
    char ch1 = 'r';
    char names[] = "Hello How are you?";
    char *games = "Hello Asian Games";
    char emp[] = "Hello emp";
    const char *letters = "Welcome to coding";
    char *players[] = {"Ronaldo", "Sachin", "Messi"};
    char nature[][6] = {"Air", "water", "fire"};
    printf("%c %c\n", ch, ch1);
    printf("%c\n", *(names+1));
    printf("%s\n", names);
    printf("%c\n", games[2]);
    printf("%c\n", emp[3]);
    printf("%s\n", emp);
    printf("%c\n", *(letters+4));
    printf("%s\n", letters);
    printf("%s\n", *players);
    printf("%c\n", nature[0][0]);
    printf("%s\n", nature[0]);
    printf("%s\n", nature[1]);
    return 0;
}

