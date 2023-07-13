#include <stdio.h>
#include <stdlib.h>

int main()//any c program starts from this function
{
	int numslist[3] = {100,200,300};// declaring & initializing an array
	int *numsptr = numslist;// declaring and initializing a pointer
	printf("numslist start at : %p\n", numsptr);//accessing the initial 
						   //address of numsptr array
	printf("numslist value %d\n", *numsptr);// accessing the initial value of
						// numsptr array
	printf("numslist value %d\n", numslist[0]);// accesing the first value 
						  // of array using indexing
	printf("numslist start at: %p\n", numsptr + 1);//incrementing the pointer
						      // location
	printf("numslist value %d\n", *(numsptr+1));//accessing the value from
						   //incremented pointer location
	printf("numslist value %d\n", numslist[1]);//accessing the array
						// with index value
	return 0;
}
