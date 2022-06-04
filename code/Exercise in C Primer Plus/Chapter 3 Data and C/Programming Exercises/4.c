#include <stdio.h>

int main(void)
{
	float flt;
	printf("Enter a floating-point value: ");
	scanf("%f", &flt);
	printf("fixed-point notation: %f\n", flt);
	printf("exponential notation: %e\n", flt);
	printf("p notation: %a\n", flt);

	return 0;
}
