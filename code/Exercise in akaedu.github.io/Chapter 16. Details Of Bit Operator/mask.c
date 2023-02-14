/* mask.c */

#include <stdio.h>

int main(void)
{
	unsigned int a, b, mask = 0x0000ff00;
	a = 0x12345678;
	b = (a & mask) >> 8; /* 0x00000056 */
	printf("0x%08x\n", b);

	unsigned int c = (a >> 8) & ~(~0U << 8);
	printf("0x%08x\n", c);

	b = a & ~mask; /* 0x12340078 */
	printf("0x%08x\n", b);

	b = a | mask; /* 0x1234ff78 */
	printf("0x%08x\n", b);

	return 0;
}
