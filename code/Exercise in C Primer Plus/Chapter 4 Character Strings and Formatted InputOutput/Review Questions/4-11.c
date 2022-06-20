/* Review Questions 4.11 */

// What's wrong with the following statement statement and how can you fix it?
// printf("The double type is %z bytes..\n", sizeof (double));

#include <stdio.h>

int main(void)
{
	// printf("The double type is %z bytes..\n", sizeof(double));
	printf("The double type is %zd bytes..\n", sizeof(double));
	printf("The double type is %#.4zx bytes..\n", sizeof(double));

	return 0;
}

/*
 * The z in %z is a modifier, not a specifier, so it requires a specifier for it to modify. You
 * could use %zd to print the result in base 10 or use a different specifier to print using a
 * different base, for example, %zx for hexadecimal.
 */
