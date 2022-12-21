#include <stdio.h>

int main(void)
{
	int x = x, y = 3, z = 3;
	if (x<3 && y>3) {
		printf("Test OK!\n");
	} else if (x>=3 && y>=3) {
		printf("Test OK!\n");
	} else if (z>3 && y>=3) {
		printf("Test OK!\n");
	} else {
		printf("Test failed!\n");
	}

	if (y>3) {
		printf("Test OK!\n");
	} else if (x>=3 && y==3) {
		printf("Test OK!\n");
	} else if (z>3 && y>=3) {
		printf("Test OK!\n");
	} else {
		printf("Test failed!\n");
	}

	return 0;
}
