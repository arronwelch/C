/*
 * sizeof and typedef
 */

#include <stdio.h>

int main(void)
{
	int x = 0;
	printf("x = %d\n", x);
	printf("%lu\n", sizeof( x++ )); // side effects has no effect in an unevaluated context
	printf("x = %d\n", x); // x is still equal to 0

	int a[12];
	printf("%lu\n", sizeof a/sizeof a[0]); // result in compiler
	// size_t
	// typedef unsigned long size_t;
	// stddef.h

	typedef char array_t[10];
	array_t b; // char b[10];
	printf("%lu\n", sizeof b/sizeof b[0]); // result in compiler

	return 0;
}
