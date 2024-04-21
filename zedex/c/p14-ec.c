#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void print_letters(char arg[]);//fwd declaration
void print_arguments(int argc, char *argv[])
{
    int i=0;
    for(i=0; i<argc; i++)
        {
            print_letters(argv[i]);
        }
}
void print_letters(char arg[])
{
    int i=0;
    for(i=0; i<strlen(arg); i++)
        {
            char ch =arg[i];
            if(isalpha(ch) || isblank(ch) || isdigit(ch))
            {
                printf(" %c == %d ", ch, ch);
            }
        }
    printf("\n");
}
int main(int argc, char *argv[]) 
{
    print_arguments(argc,argv);
    return 0;
}

