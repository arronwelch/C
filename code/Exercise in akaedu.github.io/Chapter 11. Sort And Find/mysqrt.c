/* mysqrt.c */

#include <stdio.h>
#include <assert.h>

double mysqrt(double y)
{
	assert(y > 0);
	double x = y/2;
	while ( x*x - y >= 0.001 || x*x - y <= -0.001 )
	{
		if (x*x < y)
			x += x/2;
		else if (x*x > y)
			x -= x/2;
		else
			break;
	}
	return x;
}

int main(void)
{
	double value = 4.342;
	printf("mysqrt(%f) = %f\n", value, mysqrt(value));

	return 0;
}
