#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char s[100];
    char c[100];
    char sen[100];
    scanf(" %[^\n]s", c); 
    scanf(" %[^\n]s", s); 
    scanf(" %[^\n]s", sen); 
    printf("%s\n%s\n%s\n", c, s, sen);
    return 0;
}
