/* Review Questions 4.7 */

// Which conversion specification would you use to print each of the following?
// a. An unsigned long integer in a field width of 15
// b. A hexadecimal integer in the form 0x8a in a field width of 4
// c. A floating-point number in the form 2.33E+02 that is left-justified in a field width
// of 12
// d. A floating-point number in the form +232.346 in a field width of 10
// e. The first eight characters of a string in a field eight characters wide

#include <stdio.h>

int main(void)
{
	printf("a:*%15lu*\n", 1234567890LU);
	printf("b:*%#4x*\n", 0x8a);
	printf("c:*%-12.2E*\n", 2.33E+02);
	printf("d:*%+10.3f*\n", 232.346);
	printf("e:*%8.8s*\n", "abcdefghjkl");

	return 0;
}
