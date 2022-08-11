#include <stdio.h>

extern int add(int,int);

int main(void)
{
	printf("Hello, DLL!\n");
	printf("1+2=%d\n",add(1,2));

	return 0;
}

