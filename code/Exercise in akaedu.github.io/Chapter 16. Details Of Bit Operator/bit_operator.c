/* bit_operator.c */

#include <stdio.h>

int main(void)
{
	int i = 0x01 << 31;
	printf("0x01 << 31:%08x\n", i);
	i = 0x01 << 32; // Undefined
	printf("0x01 << 32:%08x\n", i);

	int j = 0x80000000 >> 31;
	printf("0x80000000 >> 31:%08x\n", j);
	j = -8 >> 2; // Implementation-defined : x86-gcc, shift right MSB = 1
	printf("-8 >> 2:%d %08x\n", j, j);

	int k = 0xcffffff3;
	printf("%x\n", 0xcffffff3>>2); // Integer Promotion ? unsigned int
	printf("%x\n", k>>2); // k is signed int

	return 0;
}
