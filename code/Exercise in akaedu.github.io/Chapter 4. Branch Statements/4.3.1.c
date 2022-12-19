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
