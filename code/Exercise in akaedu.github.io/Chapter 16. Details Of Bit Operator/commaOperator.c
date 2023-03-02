/*
 * Comma Operator
 */

#include <stdio.h>

void f(char x, double y, int z)
{
	printf("x = %c\ny = %f\nz = %d\n", x, y, z);
}

int main(void)
{
	char a = 'A';
	int t = 0;
	int c = 123456;

	f(a, (t = 3, t+2.0), c); // "t = 3" is INT, "t+2.0" is DOUBLE

	return 0;
}
