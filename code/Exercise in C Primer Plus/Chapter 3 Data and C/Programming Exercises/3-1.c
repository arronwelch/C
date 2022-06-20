/* Programming Exercises 3.1 */

// Find out what your system does with integer overflow, floating-point overflow, and
// floating-point underflow by using the experimental approach; that is, write programs
// having these problems.(You can check the discussion in Chapter 4 of limits.h and
// float.h to get guidance on the largest and smallest values.)

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("Maximum int value on this system = %+d\n", INT_MAX);
	printf("Integer overflow: %d + 1 = %+d\n\n", INT_MAX, INT_MAX + 1);

	printf("Maximun float value on this system = %e\n", FLT_MAX);
	printf("Floating-point overflow: %e * 10 = %e\n\n", FLT_MAX, FLT_MAX * 10);

	printf("Minimum float value on this system = %e\n", FLT_MIN);
	printf("Floating-point underflow: %e / 10 = %e\n", FLT_MIN, FLT_MIN / 10);

	return 0;
}
