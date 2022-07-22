/* Review Questions 5-10.c */

/* 10. If the following fragments were part of a complete program, what would they print?
 *         a.
 *         int x = 0;
 *         while (++x < 3)
 *             printf("%4d", x);
 *
 *         b.
 *         int x = 100;
 *
 *         while (x++ < 103)
 *             printf("%4d\n",x );
 *             printf("%4d\n",x );
 *
 *         c.
 *         char ch = 's';
 *
 *         while (ch < 'w')
 *         {
 *             printf("%c", ch);
 *             ch++;
 *         }
 *         printf("%c\n", ch);
 */

#include <stdio.h>

int main(void)
{
    // a.
	printf("a.start>>>\n");
	int x = 0;
	while (++x < 3)
		printf("%4d", x);

	printf("\n<<<a.end\n");

	// b.
	printf("b.start>>>\n");

 	/* int */ x = 100;
 
 	while (x++ < 103)
		printf("%4d\n",x );
		printf("%4d\n",x );
	printf("\n<<<b.end\n");

	printf("c.start>>>\n");
	char ch = 's';
	while (ch < 'w')
	{
		printf("%c", ch);
		ch++;
	}
	printf("%c", ch);
	printf("\n<<<c.end\n");

	return 0;
}

// gcc 5-10.c && ./a.out > 5-10.c.printlog

/*
10. Here is the output for each example:
	a.   1   2
	Note that x is incremented and then compared.The cutsor is left on the same line.

	b.
	 101
	 102
	 103
	 104

	Note that this time x is compared and then incremented.In both this case
	and in example a, x is incremented before printing take place.Note too,that
	indenting the second printf() statement does not make it part of the while loop.
	Therefore, it is called only once, after the while loop ends.

	c.
	stuv
	Here,there is no incrementing until after the first printf().
*/
