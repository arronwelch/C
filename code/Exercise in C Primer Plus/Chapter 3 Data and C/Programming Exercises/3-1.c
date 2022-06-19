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
	//integer overflow
	int i = INT_MAX + 1;
	printf("%d\n", i);

	//floating-point overflow
	//float fo = DBL_MAX;
	float fo = FLT_MAX * 10;
	printf("%f\n", fo);

	//floating-point underflow
	//float fu = DBL_MIN;
	float fu = FLT_MIN / 10;
	printf("%f\n", fu);

	return 0;
}
