// Listing 5.4 The squares.c Program

/* squares.c -- produces a table of first 20 squares */

#include <stdio.h>

int main(void)
{
	int num = 1;

	while (num < 21)
	{
		printf("%4d %6d\n", num, num * num);
		num = num + 1;
	}

	return 0;
}
