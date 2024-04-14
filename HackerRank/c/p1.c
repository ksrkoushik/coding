#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	
    char s[100];
    char *p = malloc(100 *sizeof(char));
    int m;
    char t[100];
    //This line gets all the words given as input,
    //if a sentence is written with spaces then the %s wont work.
    scanf("%[^\n]%*c",s);
    scanf("%[^\n]%*c",p);
    scanf("%d\n", &m);
    scanf("%[^\n]%*c", t);
    printf("Hello, World!\n");
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    printf("%s\n", s); 
    printf("%s\n", p);
    printf("%d\n", m);
    printf("%s\n", t);
    printf("Good Bye!!");
    return 0;

}


