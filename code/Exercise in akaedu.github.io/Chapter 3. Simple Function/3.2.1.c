#include <stdio.h>

int main(void)
{
	int hour = 11;
	int minute = 59;
	printf("%d and %d hours\n", hour, minute / 60);
	return 4; // "return 0;" is automatically added
}

/*
 * $ clang 3.2.1.c
 * $ ./a.out
 * 11 and 0 hours
 * $ echo $?
 * 4
 */
