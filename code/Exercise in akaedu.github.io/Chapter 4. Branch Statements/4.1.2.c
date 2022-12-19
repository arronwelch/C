#include <stdio.h>

void foo(void)
{
	int i = 0;
	{
		int i = 1;
		int j = 2;
		printf("i=%d, j=%d\n", i, j);
	}
	printf("i=%d\n", i); /* cannot access j here */
}

int main(void)
{
	foo();
	return 0;
}
