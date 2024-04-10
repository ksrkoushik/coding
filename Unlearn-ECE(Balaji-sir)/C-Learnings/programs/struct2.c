#include <stdio.h>

int main(int argc, char *argv[])
{
	struct student
	{
		char *names[3];
		int marks[3];
	};

	struct student Ravi;
	Ravi.names[0] = "English";
    	Ravi.names[1] = "Maths";
        Ravi.names[2] = "Science";

        Ravi.marks[0] = 87;
        Ravi.marks[1] = 67;
        Ravi.marks[2] = 88;

       // Calculate the number of subjects
       int count = sizeof(Ravi.marks) / sizeof(Ravi.marks[0]);

       // Iterate over the subjects and print their names and marks
       for (int i = 0; i < count; i++) 
       {
	       printf("Subject name is %s and marks is %d\n", Ravi.names[i], Ravi.marks[i]);
       }
       return 0;
}
