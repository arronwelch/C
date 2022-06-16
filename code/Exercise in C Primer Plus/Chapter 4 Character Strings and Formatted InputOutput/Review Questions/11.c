/* 11.c */
#include <stdio.h>

int main(void)
{
	// printf("The double type is %z bytes..\n", sizeof(double));
	printf("The double type is %zd bytes..\n", sizeof(double));
	printf("The double type is %#.4zx bytes..\n", sizeof(double));

	return 0;
}
