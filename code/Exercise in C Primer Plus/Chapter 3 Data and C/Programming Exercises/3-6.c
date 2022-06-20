/* Programming Exercises 3.6 */

// The mass of a single molecule of water is about 3.0x10^(-23) grams. A quart of water is 
// about 950 grams. Write a program that requests an amount of water, in quarts, and 
// displays the number of water molecules in that amount.

#include <stdio.h>

int main(void)
{
	float num;

	printf("Please enter an amount of water,in quarts:\n");
	scanf("%f", &num);

	printf("the number of water molecules is: %e\n", num * 950.0 / 3e-23);

	return 0;
}
