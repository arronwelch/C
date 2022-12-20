#include <stdio.h>

int main(void)
{
	int a = 1, b = 2, c = 4;
	if (a < b) {
		if (b < c) {
			printf("b is between a and c.\n");
		}
	}

	if (a < b && b < c) {
		printf("b is between a and c.\n");
	}
	return 0;
}

/*
 * A B A AND B
 * 0 0 0
 * 0 1 0
 * 1 0 0
 * 1 1 1
 */

/*
 * A B A OR B
 * 0 0 0
 * 0 1 1
 * 1 0 1
 * 1 1 1
 */

/*
 * A NOT A
 * 0 1
 * 1 0
 */
