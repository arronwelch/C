#include <stdio.h>

int main(void)
{
	float cm;
	printf("Please enter your height in centimeters: ___\b\b\b");
	scanf("%f", &cm);
	printf("your height in inches: %f\n", cm / 2.54);

	return 0;
}
