/*
 * Conditional Operator
 */

#include <stdio.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main(void)
{
	int a, b;
	a = 1;
	b = 2;

	printf("max(%d, %d) = %d\n", a, b, max(a, b));

	return 0;
}
