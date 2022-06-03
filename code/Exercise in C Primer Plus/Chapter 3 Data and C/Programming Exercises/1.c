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
