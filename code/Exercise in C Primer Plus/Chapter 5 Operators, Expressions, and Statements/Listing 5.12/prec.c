#include <stdio.h>

int main(void)
{
	int y = 2;
	int n = 3;
	int nextnum = (y + n++)*6;

	printf("nextnum = %d\n", nextnum);

	printf("y = %d\n", y);
	printf("n = %d\n", n);
	int x = y*n++;
	printf("y*n++ = %d\n", x);

	return 0;
}
