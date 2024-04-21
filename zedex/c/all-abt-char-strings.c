#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *letters = "Hanuman";
    int m = strlen(letters);
    for (int j=0; j<m; j++)
        {
            printf("%c", letters[j]);
        }
    printf("\n");
    char emp[] = "Hello employee";
    int n = strlen(emp);
    for (int k=0; k<n; k++)
        {
            printf("%c", emp[k]);
        }
    printf("\n");
    char *names[] = {"Sachin", "Sri", "Ram"};
    int c = sizeof(names)/sizeof(names[0]);
    for (int i=0; i<c; i++)
        {
            printf("%s %s\n", names[i], *(names+i));
        }
    char *games = "hello asian";
    int d = strlen(games);
    for (int f=0; f<d; f++)
        {
            printf("%c", games[f]);
        }
    printf("\n");
    return 0;
}

