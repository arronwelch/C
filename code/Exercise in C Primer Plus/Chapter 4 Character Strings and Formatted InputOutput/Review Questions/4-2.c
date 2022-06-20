/* Review Questions 4.2 */

// Assuming that each of the following examples is part of a complete program, what will
// each one print?

#include <stdio.h>
#include <string.h>		// strlen()

int main(void)
{
	printf("a: He sold the painting for $%2.2f.\n", 2.345e2);
	printf("b: %c%c%c\n", 'H', 105, '\41');

#define Q "His Hamlet was funny without being vulgar."
	printf("c: %s\nhas %ld characters.\n", Q, strlen(Q));

	printf("d: Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0);

	return 0;
}
