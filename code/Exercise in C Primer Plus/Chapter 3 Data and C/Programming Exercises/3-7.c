/* Programming Exercises 3.7 */

// There are 2.54 centimeters to the inch. Wrire a program that asks you to enter your
// height in inches and then displays your height in centimeters. Or, if you prefer, ask for
// the height in centimeters and convert that to inches.

#include <stdio.h>

int main(void)
{
	float cm;

	printf("Please enter your height in centimeters:\n");
	scanf("%f", &cm);

	printf("your height in inches: %f\n", cm / 2.54);

	return 0;
}
