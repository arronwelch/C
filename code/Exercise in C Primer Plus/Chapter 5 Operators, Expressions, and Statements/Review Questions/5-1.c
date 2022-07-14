/* Review Questions: 5-1.c */
/*
 * 1. Assume all variables are of type int. Find the value of each of the following variables:
 *     a. x = (2 + 3) * 6;
 *     b. x = (12 + 6)/2*3;
 *     c. y = x = (2 + 3)/4;
 *     d. y = 3 + 2*(x = 7/2);
 */

#include <stdio.h>

int main(void)
{
	int x = 0, y = 0;

	x = (2 + 3) * 6;
	printf("x = %d, y = %d\n", x, y);

	x = (12 + 6)/2*3;
	printf("x = %d, y = %d\n", x, y);

	y = x = (2 + 3)/4;
	printf("x = %d, y = %d\n", x, y);

	y = 3 + 2*(x = 7/2);
	printf("x = %d, y = %d\n", x, y);

	return 0;
}
