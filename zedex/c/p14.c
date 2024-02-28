#include <stdio.h>
#include <ctype.h>

//forward declarations
<<<<<<< HEAD

int can_print_it(char ch);
void print_letters(char arg[]);

=======
int can_print_it(char ch);
void print_letters(char arg[]);
>>>>>>> b8ccae09701f1d1f738105583d514ac59bab4505
void print_arguments(int argc, char *argv[])
{
	int i = 0;
	for(i = 0; i < argc; i++)
	{
		print_letters(argv[i]);
	}
}

void print_letters(char arg[])
{
	int i = 0;
	for(i = 0; arg[i] != '\0'; i++)
	{
		char ch = arg[i];
<<<<<<< HEAD
		if(can_print_it(ch))
		{
			printf("'%c' == %d ", ch, ch);
		}
		printf("\n");
	}
=======
		if (can_print_it(ch))
		{
			printf("'%c' == %d ", ch, ch);
		}
	}
	printf("\n");
>>>>>>> b8ccae09701f1d1f738105583d514ac59bab4505
}

int can_print_it(char ch)
{
	return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}
<<<<<<< HEAD
=======


>>>>>>> b8ccae09701f1d1f738105583d514ac59bab4505
