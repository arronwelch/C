#include <stdio.h>

int main(void)
{
	printf("a:*%15lu*\n", 1234567890L);
	printf("b:*%#4x*\n", 0x8a);
	printf("c:*%-12.2E*\n", 2.33E+02);
	printf("d:*%+10.3f*\n", 232.346);
	printf("e:*%8.8s*\n", "abcdefghjkl");

	return 0;
}
