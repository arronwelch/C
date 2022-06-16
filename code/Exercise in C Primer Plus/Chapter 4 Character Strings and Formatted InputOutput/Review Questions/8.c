#include <stdio.h>

int main(void)
{
	int width = 6;
	printf("a:*%6.4d*\n", 12);
	printf("b:*%#*o*\n", width, 012);
	printf("c:*%2c*\n", 'A');
	printf("d:*%+.2f*\n", 3.13);
	printf("e:*%-7.5s*\n", "abcdefghjkl");

	return 0;
}
