// Listing 4.12 The floatcnv.c Program
/* floatcnv.c -- mismatched floating-point conversions */

#include <stdio.h>

int main(void)
{
	float n1 = 3.0;
	double n2 = 3.0;
	long n3 = 2000000000;
	long n4 = 1234567890;

	printf("On this system sizeof(float) = %zd\n", sizeof(float));
	printf("On this system sizeof(double) = %zd\n", sizeof(double));
	printf("On this system sizeof(long) = %zd\n\n", sizeof(long));

	printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
	printf("%ld %ld\n", n3, n4);
	printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
	printf("%ld %ld %ld %ld\n", n4, n3, n2, n1);
	printf("%ld %ld %ld %ld\n", n3, n4, n2, n1);
	printf("%ld %ld %ld %ld\n", n3, n4, n1, n2);

	return 0;
}
