/* Programming Exercises 3.4 */

// Write a program that reads in a floating-point number and prints it first in decimal-point
// notation, then in exponential notation, and then, if your system supports it, p notation.
// Have the output use the following format (the actual number of digits displayed for the
// exponent depends on the system):

// Enter a floating-point value: 64.25
// fixed-point notation: 64.250000
// exponential notation: 6.425000e+01
// p notation: 0x1.01p+6

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
