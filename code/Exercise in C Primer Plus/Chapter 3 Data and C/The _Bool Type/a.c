#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	if(0)
		printf("0 is true\n");
	else
		printf("0 is false\n");

	if(-1)
		printf("-1 is true\n");
	else
		printf("-1 is false\n");

	if(1)
		printf("1 is true\n");
	else
		printf("1 is false\n");

	bool c = -1;
	printf("c = -1 : %d\n", c);

	return 0;
}
