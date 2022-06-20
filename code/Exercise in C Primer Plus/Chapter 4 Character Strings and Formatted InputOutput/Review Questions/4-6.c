/* Review Questions 4.6 */

// What conversion specification would you use to print each of the following?
// a. A decimal integer with a field width equal to the number of digits
// b. A hexadecimal integer in the form 8A in a field width of 4
// c. A floating-point number in the form 232.346 with a field width of 10
// d. A floating-point number in th form 2.33e+002 with a field width of 12
// e. A string left-justified in a field of width 30

#include <stdio.h>

int main(void)
{
	printf("a:*%d*\n", 10);
	printf("b:*%4X*\n", 0x8A);
	printf("c:*%10.3f*\n", 232.346);
	printf("d:*%12.2e*\n", 2.33e2);
	printf("e:*%-30s*\n", "This is a test string");

	return 0;
}
