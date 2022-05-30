#include <stdio.h>
#include <math.h>

int main(void)
{
	float f32_nan = asin(1.2);
	printf("%e\n", f32_nan);//nan, or not-a-number

	return 0;
}
