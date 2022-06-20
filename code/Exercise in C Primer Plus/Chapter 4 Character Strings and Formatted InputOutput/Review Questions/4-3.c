/* Review Questions 4.3 */

// In Question 2(c), what changes could you make so that string Q is printed out enclosed in
// double quotation marks?

#include <stdio.h>
#include <string.h>		// strlen()

int main(void)
{
#define Q "His Hamlet was funny without being vulgar."
	printf("\"%s\"\nhas %ld characters.\n", Q, strlen(Q));

	return 0;
}
