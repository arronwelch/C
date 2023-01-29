/* mysqrt.c */

#include <stdio.h>
#include <assert.h>

double mysqrt(double y)
{
	assert(y > 0);
	double d = 0, x = 0;
	x = d = y / 2;
	while ( x*x - y >= 0.001 || x*x - y <= -0.001 )
	{
		printf("x = %f\n", x);
		if (x*x < y)
			x += d/2;
		else if (x*x > y)
			x -= d/2;
		else
			break;
		d = d/2;
	}
	return x;
}

int main(void)
{
	double value = 4.342;
	printf("mysqrt(%f) = %f\n", value, mysqrt(value));

	return 0;
}
