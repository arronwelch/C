/* Review Questions 3.6 */

// Identify the data type (as used in declaration statements) and the printf() format
// specifier for each of the following constants:

// Constant			type				specifier
// a. 12			int					%d
// b. 0X3			unsigned int		%#X
// c. 'C'			char(really int)	%c
// d. 2.34E07		double				%.2E
// e. '\040'		char(really int)	%c
// f. 7.0			double				%.1f
// g. 6L			long				%ld
// h. 6.0f			float				%f
// i. 0x5.b6p12		double				%a

#include <stdio.h>

int main(void)
{
	printf("a. %d\n", 12);
	printf("b. %#X\n", 0X3);
	printf("c. '%c'\n", 'C');
	printf("d. %.2E\n", 2.34E07);
	printf("e. '%c'\n", '\040');
	printf("f. %.1f\n", 7.0);
	printf("g. %ld\n", 6L);
	printf("h. %.1f\n", 6.0f);
	printf("i. %a\n", 0x5.b6p12);	/* Note the result is 0x1.6d8p+14 */

	return 0;
}
