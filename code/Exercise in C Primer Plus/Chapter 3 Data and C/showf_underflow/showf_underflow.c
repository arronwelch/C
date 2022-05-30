#include <stdio.h>

int main(void)
{
	float toosmall = 3.4E-38 * 1.0E-12f;
	printf("%e\n", toosmall);

	return 0;
}
