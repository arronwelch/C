#include <stdio.h>

int main(void)
{
	int x = 1;
	if (x > 0) {
		printf("x is positive.\n");
	} else {
		if (x < 0)
			printf("x is negative.\n");
		else
			printf("x is zero.\n");
	}
	return 0;
}
