#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *names[] = {"Vish", "Dhruv", "Sri"};
    printf("%p %s\n", names, *names);//address of names array itself(means names[0])
    printf("%p %s\n", &names, *names);//address of names array itself(means names[0])
    printf("%p %s\n", *names, *names);//address pointing to the address of the element 
				      //present in names[0] is present(In this case, 
				      //it is the address of "Vish")
    printf("%p %s\n", &names[0], names[0]);//address of names[0] 
    printf("%p %s\n", names[0], names[0]);//address pointing to element present in names[0]
    printf("%p %s\n", *(names+1), *(names+1));//address pointing to element present in
					      //names[1](In this case, it os "Dhruv")
    printf("%p %s\n", &names[1], names[1]);//address of names[1]
    printf("%p %s\n", names[1], names[1]); //address pointing to element present in 
					   //names[1]
    printf("%p %s\n", *(names+2), *(names+2));//address pointing to element present in
					      //names[2]
    printf("%p %s\n", &names[2], names[2]);//address of names[2] 
    printf("%p %s\n", names[2], names[2]);//address pointing to element present in
					  //names[2]
    printf("%p %s\n", (*names)+1, (*names)+1);//address pointing to 
					      //1st element 2nd letter "ish"
    return 0;
}
