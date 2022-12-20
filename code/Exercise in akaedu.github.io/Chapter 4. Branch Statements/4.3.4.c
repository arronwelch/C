#include <stdio.h>

int main(void)
{
	int x = 2, y = 1;
	if (x > 1 && y != 1) {
		printf("if\n");
	} else if ( x < 1 && y != 1) {
		printf("else if\n");
	} else {
		printf("else\n");
	}

	if ( x == 1 || y == 1) {
		printf("user define.\n");
	}
}
