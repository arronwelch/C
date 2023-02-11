/* gcc integer.c -std=c99
 * LP64 in macos m1 is arm-64
 * clang integer.c is "long" to "int"
 */

#include <stdio.h>

int main(void)
{
	printf("sizeof(char)=%lu\n", sizeof(char));
	printf("sizeof(short)=%lu\n", sizeof(short));
	printf("sizeof(int)=%lu\n", sizeof(int));
	printf("sizeof(long)=%lu\n", sizeof(long));
	printf("sizeof(long long)=%lu\n", sizeof(long long));
	printf("1:%d\n", -2147483648); // "-2147483648" is "(-1)" multiply "long" type integer 2147483648, expression is "long" type.
	printf("2:%d\n", -2147483647-1); // "int" type integer "-2147483647" subtract "int" type integer 1, expression is "int" type.
	printf("3:%ld\n", -2147483648); // "%ld" is expect "long" type integer, so no warning.
	long long i = 1234567890 * 1234567890; // 1234567890 is "int" type, result is over "int" type.
	long long ii = 1234567890LL * 1234567890;
	int data_bit = 0b0001111;
	printf("data_bit = %d\n", data_bit);

	return 0;
}
