/* multiply.c */

#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y);

unsigned int multiply(unsigned int x, unsigned int y)
{
	unsigned int ret = 0, mask = 0x01, BitRank = 0;
	while(y)
	{
		if (y & mask)
			ret += (x << BitRank);
		y &= ~mask;
		mask <<= 1;
		BitRank++;
	}
	return ret;
}

int main(void)
{
	unsigned int result = multiply(0b11011, 0b10010);
	printf("%d * %d = 0x%08x\n", 0b11011, 0b10010, result);
	printf("%d * %d = 0x%08x\n", 0b11011, 0b10010, (0b11011 << 1) + (0b11011 << 4));
	printf("%d * %d = 0x%08x\n", 0b11011, 0b10010, 0b11011 * 0b10010);

	return 0;
}
