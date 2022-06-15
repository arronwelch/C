#include <stdio.h>
#include <string.h>		// strlen()

int main(void)
{
#define Q "His Hamlet was funny without being vulgar."
	printf("\"%s\"\nhas %ld characters.\n", Q, strlen(Q));

	return 0;
}
