#include <stdio.h>

enum coordinate_type { RECTANGULAR = 1, POLAR };

int main(void)
{
	int RECTANGULAR; // this is no-initialize local variable
	printf("%d %d\n", RECTANGULAR, POLAR);
	return 0;
}
