/*
 * conditional operator
 * ternary operator
 * trinary operator
 * Right to Left(RTL) associativity
 * a ? b : c ? d : e
 *(a ? b : c)? d : e
 * or
 * a ? b :(c ? d : e)
 */

#include <stdio.h>

int main(void)
{
	int a = 1, b = 5, c = 4, d = 3, e = 2;
	printf("%d\n", a ? b : c ? d : e);

	return 0;
}
