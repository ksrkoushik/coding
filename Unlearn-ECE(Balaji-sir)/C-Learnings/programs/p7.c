#include <stdio.h>

int main(int argc, char*argv[])
{
	char a[10];
	scanf("%s", a);//you can pass either &a[0] or a or &a
	printf("%c", a[0]);
	printf("\n");
	char b[] = "welcome";
	printf("%s", b);
	printf("\n");
	char c[] = "Surabee";
	for(int i=0; i<8; i++)
	{
		b[i] = c[i];
	}
	printf("%s", b);
	printf("\n");
	int d;
	d = sizeof(b)/sizeof(char);
	printf("%d\n", d);
	printf("int size is %ld\n", sizeof(int));
	printf("long size is %ld\n", sizeof(long));
	printf("short size is %ld\n", sizeof(short));
	printf("char size is %ld\n", sizeof(char));
	printf("long long size is %ld\n", sizeof(long long));
	printf("%ld\n", sizeof(a));
	return 0;
}
