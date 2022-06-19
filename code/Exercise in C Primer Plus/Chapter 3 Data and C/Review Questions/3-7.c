/* Review Questions 3.7 */\

// Identify the data type (as used in declaration statements) and the printf() format
// specifier for each of the following constants (assume a 16-bit int):

// Constant				Type				Specifier
// a. 012				unsigned int		%#o or %#O
// b. 2.9e05L			long double			%.1lf
// c. 's'				char(really int)	%c
// d. 100000			long int			%ld
// e. '\n'				char(really int)	%c
// f. 20.0f				float				%.1f
// g. 0x44				unsigned int		%#x
// h. -40				int					%+d

#include <stdio.h>

int main(void)
{
	printf("a. %#o\n", 012);
	printf("b. %.1Le\n", 2.9e05L);
	printf("c. '%c'\n", 's');
	printf("d. %d\n", 100000);
	printf("e. '%c'\n", '\n');
	printf("f. %.1f\n", 20.0f);
	printf("g. %#x\n", 0x44);
	printf("h. %d\n", -40);

	return 0;
}
