/* Programming Exercises 3.8 */

// In the U.S. system of volume measurements, a pint is 2 cups, a cup is 8 ounces, an
// ounce is 2 tablespoons, and a tablespoon is 3 teaspoons. Write a program that requests a
// volume in cups and that displays the equivalent volumes in pints, ounces, tablespoons,
// and teaspoons. Why does a floating-point type make more sense for this application than
// an integer type?
 
#include <stdio.h>

int main(void)
{
	float cups;

	printf("Please enter a volume in cups:\n");
	scanf("%f", &cups);

	printf("the equivalent in pins: %f\n", cups / 2.0);
	printf("the equivalent in ounces: %f\n", cups * 8.0);
	printf("the equivalent in tablespoons: %f\n", cups * 16.0);
	printf("the equivalent in teaspoons: %f\n", cups * 48.0);
	
	return 0;
}
