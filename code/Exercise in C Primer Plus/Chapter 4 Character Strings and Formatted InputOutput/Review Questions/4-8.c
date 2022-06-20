/* Review Questions 4.8 */

// What conversion specification would you use to print each of the following?
// a. A decimal integer having a minimum of four digits in a field width of 6
// b. An octal integer in a field whose width will be given in the argument list
// c. A character in a field width of 2
// d. A floating-point number in the form +3.13 in a field width equal to the number of
//    characters in the number
// e. The first five characters in a string left-justified in a field of width 7

#include <stdio.h>

int main(void)
{
	int width = 6;
	printf("a:*%6.4d*\n", 12);
	printf("b:*%#*o*\n", width, 012);
	printf("c:*%2c*\n", 'A');
	printf("d:*%+.2f*\n", 3.13);
	printf("e:*%-7.5s*\n", "abcdefghjkl");

	return 0;
}
