/* Programming Exercises 3.5 */

// There are approximately 3.156 x 10^7 seconds in a year.Write a program that requests
// your age in years and then displays the equivalent number of seconds.

#include <stdio.h>

int main(void)
{
	float age;

	printf("Please enter your age: ");
	scanf("%f", &age);

	printf("the equivalent number of seconds: %f s\n", age*3.156e7);

	return 0;
}
