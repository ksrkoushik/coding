#include <stdio.h>
#include <stdlib.h>
void findMinMax(int num1, int num2, int *pMax, int *pMin)
{
	if(num1>num2)
	{
		*pMax = num1;//the value of num1 is passed to the
			    // address of pMax and is stored at the location
		*pMin = num2;//the value of num2 is passed to the
			    // address of pMin and is stored at the location
	}
	else
	{
		*pMax = num2;//the value of num2 is passed to the
			    //address of pMax and is stored at the location
		*pMin = num1;//the value of num1 is passed to the address of
			    //pMin and is stored at the location.
	}		
}

int main()
{
	int a = 5, b = 7;
	int *ptr1, *ptr2;// declaring pointer variables 
	int max,min;
	ptr1 = &a;// holding the address of 'a'
	ptr2 = &b;// holding the address of 'b'
	findMinMax(*ptr1,*ptr2,&max,&min);//passing a and b as arguments to function
				// and then passing addresses which are assigned to 
				// the arguments passed
	printf("max b/w %d and %d is %d\n",*ptr1,*ptr2,max);
	printf("min b/w %d and %d is %d\n",*ptr1,*ptr2,min);

	*ptr1 = *ptr1 + 150;
	*ptr2 = *ptr2 *17;
	findMinMax(*ptr1,*ptr2,&max,&min);//passing a and b as arguments to function
				// and then passing addresses which are assigned to 
				// the arguments passed
	printf("max b/w %d and %d is %d\n",*ptr1,*ptr2,max);
	printf("min b/w %d and %d is %d\n",*ptr1,*ptr2,min);
	
	return 0;
}
	
