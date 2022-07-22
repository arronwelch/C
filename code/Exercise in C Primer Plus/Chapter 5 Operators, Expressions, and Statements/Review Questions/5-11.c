/* Review Questions: 5-11.c */

/*
11.What will the following program print?
#define MESG "COMPUTER BYTES DOG"
#include <stdio.h>
int main(void)
{
	int n = 0;

	while ( n < 5 )
		printf("%s\n", MESG);
		n++;
	printf("That's all.\n");
	return 0;
}
*/

#define MESG "COMPUTER BYTES DOG"
#include <stdio.h>
int main(void)
{
	int n = 0;

	while ( n < 5 )
		printf("%s\n", MESG);
		n++;
	printf("That's all.\n");
	return 0;
}

// gcc 5-11.c && ./a.out > 5-11.c.printlog

/*
11. This is an ill-constructed program. Because the while statement doesn't use braces, only
	the printf() statement is part of the loop,so the program prints the message COMPUTER BYTES
	DOG indefinitely until you can kill the program.
*/
