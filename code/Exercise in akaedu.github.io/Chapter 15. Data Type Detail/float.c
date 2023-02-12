#include <stdio.h>

int main(void)
{
	float f = 1.0f;
	double d = 1.1;
	long double ld = 1.2l;

	printf("sizeof(f) = %lu\n", sizeof(f));
	printf("sizeof(d) = %lu\n", sizeof(d));
	printf("sizeof(ld) = %lu\n", sizeof(ld));

	return 0;
}
