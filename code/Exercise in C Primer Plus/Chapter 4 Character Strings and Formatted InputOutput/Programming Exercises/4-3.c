/* Programming Exercises 4.3 */

// Write a program that reads in a floating-point number and prints it first in decimal-point
// notation and then in exponential notation. Have the output use the following formats
// (the number of digits shown in the exponent may be different for your system):

// a. The input is 21.3 or 2.1e+01.
// b. The input is +21.290 or 2.129E+01.

#include <stdio.h>

int main(void)
{
	float input;
	printf("Please enter a floating-point:\n");
	scanf("%f", &input);
	printf("a. The input is %.1f or %.1e.\n", input, input);
	printf("b. The input is %+.3f or %.3E.\n", input, input);

	return 0;
}
