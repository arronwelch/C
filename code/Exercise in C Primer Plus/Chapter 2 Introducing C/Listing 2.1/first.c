/* Listing 2.1 The first.c Program */
/* gcc --std=c90 first.c */
/* ./a.out */
#include <stdio.h>
int main(void)			/* a simple program */
{
	int num;			/* define a variable called num */
	num = 1;			/* assign a value to num */

	printf("I am a simple ");	/* use the printf() function */
	printf("computer.\n");		/* newline character */
	printf("computer.\b\t");	/* backspace tab */
	printf("My favorite number is %d because it is first.\n", num);

	return 0;
}
