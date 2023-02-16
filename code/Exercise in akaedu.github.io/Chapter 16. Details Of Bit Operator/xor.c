/* xor.c */

#include <stdio.h>

int main(void)
{
	unsigned int x = 0b10101101;
	printf("product zero: 0x%08x ^ 0x%08x = 0x%08x\n", x, x, x^x);

	unsigned int a, b, mask = 1U << 6;
	a = 0x12345678;
	b = a ^ mask; /* flip the 6th bit */
	printf("flip the 6th bit: 0x%08x to 0x%08x\n", a, b);

	printf("parity check: 1 ^ 1 ^ 0 ^ 1 = %d\n", 1 ^ 1 ^ 0 ^ 1);
	printf("parity check: 1 ^ 1 ^ 1 ^ 1 = %d\n", 1 ^ 1 ^ 1 ^ 1);

	a = a ^ b; // a0 ^ b0
	b = b ^ a; // b0 ^ a0 ^ b0 => a0
	a = a ^ b; // a0 ^ b0 ^ a0 => b0
	printf("a = 0x%08x, b = 0x%08x\n", a, b);

	return 0;
}
