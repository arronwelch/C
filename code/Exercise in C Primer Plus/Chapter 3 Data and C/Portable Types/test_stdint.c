#include <stdio.h>
//#include <stdint.h>
#include <inttypes.h> // The inttypes.h header file includes stdint.h

int main(void)
{
	int32_t bit32 = 0x12345678; // int32_t represents the type for a 32-bit signed integer.
	printf("bit32 = %#x\n", bit32);
	
	int_least8_t least8 = 0x5A; // int_least8_t will be an alias for the smallest available type that can hold an 8-bit signed integer value.
	printf("least8 = %#x\n", least8);

	int_fast8_t fast8 = 0x66; // int_fast8_t will be defined as an alternative name for the integer type on your system that allows the fastest calculations for 8-bit signed values.
	printf("fast8 = %#x\n", fast8);

	intmax_t max_bit = 0x1234567890;
	printf("max_bit = %#lx\n", max_bit);

	return 0;
}
