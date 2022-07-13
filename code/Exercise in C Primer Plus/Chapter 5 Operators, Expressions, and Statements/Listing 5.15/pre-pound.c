/* Listing 5.15 The pound.c Program */

/* pre-pound.c -- defines a pre-ANSI function with absence argument */

#include <stdio.h>

// void pound(int n);	// ANSI function prototype declaration
void pound();	/* pre-ANSI function declaration */

int main(void)
{
	int times = 5;
	char ch = '!';	// ASCII code is 33
	float f = 6.0f;

	pound(times);	// int argument

	/* in the absence of a prototype, C automatically promotes char and short */
	/* arguments to in */
	pound(ch);		// same as pound((int)ch);

	/* float is automatically promoted to double */
	// pound(f);		// same as pound((double)f);

	/* this still might not help if the value of f is too large to fit into type int */
	pound((int)f);		// same as pound((int)f);

	return 0;
}

void pound(int n)	// ANSI-style function header
{					// says takes one int argument
	unsigned long cnt = 0;
	while (n-- > 0)
		cnt++;

	printf("'#' count = %lu", cnt);
	printf("\n");
}
