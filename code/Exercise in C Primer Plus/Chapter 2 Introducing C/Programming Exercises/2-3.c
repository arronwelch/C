/* Programming Exercises 2.3 */

// Write a program that converts your age in years to days and displays both values. At this
// point, don't worry about fractional years and leap years.

#include <stdio.h>

int main(void)
{
	int years, days;

	years = 18;
	days = years * 365;
	printf("your age in years is:%d\nSo, your age in days is:%d\n", years, days);

	return 0;
}
