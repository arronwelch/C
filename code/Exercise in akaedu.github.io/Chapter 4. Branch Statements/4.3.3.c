#include <stdio.h>

int main(void)
{
	int x = -1, y = 1;
	if (x > 0)
		printf("Test OK!\n");
	else if ( x <= 0 && y > 0)
		printf("Test OK!\n");
	else
		printf("Test failed!\n");

	if ( x <= 0 && y <= 0)
		printf("Test failed!\n");
	else
		printf("Test OK!\n");
}
