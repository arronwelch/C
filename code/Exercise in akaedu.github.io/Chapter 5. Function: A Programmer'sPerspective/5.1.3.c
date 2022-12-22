#include <stdio.h>

void foo(int x, int y)
{
	if (x >= 0 && y >= 0) {
		printf("both x and y are positive.\n");
		return;
	} else if ( x < 0 && y < 0) {
		printf("both x and y are negative.\n");
		return;
	}
	printf("x has a different sign from y.\n");
}

int main(void)
{
	foo( 1, 1);
	foo( 1,-1);
	foo(-1, 1);
	foo(-1,-1);
	return 0;
}
