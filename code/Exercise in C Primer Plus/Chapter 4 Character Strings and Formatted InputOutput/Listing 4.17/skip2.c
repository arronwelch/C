// Listing 4.17 The skip2.c Program
/* skip2.c -- skips over first two integers of input */

#include <stdio.h>

int main(void)
{
	int n;

	printf("Please enter three integers:\n");
	scanf("%*d %*d %d", &n);
	printf("The last integer was %d\n", n);

	return 0;
}
