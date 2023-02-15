/* rotate_right.c */

#include <stdio.h>

unsigned int rotate_right(unsigned int x, unsigned int y);

unsigned int rotate_right(unsigned int x, unsigned int y)
{
	unsigned int tmp = 0;

	while(y--)
	{
		tmp = x & 0x01;
		x >>= 1;
		if (tmp)
			x |= 0x80000000;
	}

	return x;
}

int main(void)
{
	printf("rotate_right(0x%08x, %d) = 0x%08x\n", 0xdeadbeef, 8, rotate_right(0xdeadbeef, 8));
	printf("0x%08x >> %d) = 0x%08x\n", 0xdeadbeef, 8, 0xdeadbeef >> 8);

	return 0;
}
