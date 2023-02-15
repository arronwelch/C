/* multiply.c */

#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y);

unsigned int multiply(unsigned int x, unsigned int y)
{
	unsigned int ret = 0, mask = 0x01, BitWeight = 0;
	while(y)
	{
		if (y & mask)
			ret += (x << BitWeight);
		y &= ~mask;
		mask <<= 1;
		BitWeight++;
	}
	return ret;
}

int main(void)
{
	unsigned int result = multiply(0b11011, 0b10010);
	printf("0x%08x\n", result);
	printf("0x%08x\n", (0b11011 << 1) + (0b11011 << 4));

	return 0;
}
