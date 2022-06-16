#include <stdio.h>

int main(void)
{
	printf("a:*%d*\n", 10);
	printf("b:*%4X*\n", 0x8A);
	printf("c:*%10.3f*\n", 232.346);
	printf("d:*%12.2e*\n", 2.33e2);
	printf("e:*%-30s*\n", "This is a test string");

	return 0;
}
