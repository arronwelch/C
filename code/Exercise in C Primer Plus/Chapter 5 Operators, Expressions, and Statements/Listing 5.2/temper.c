// Listing 5.2.1 The temper.c Program

/* temper.c -- conversions Centigrade to Fahrenheit */

#include <stdio.h>
#define ADJUST 32.0				// one kind of symbolic constant

int main(void)
{
	const double SCALE = 1.8;	// another kind of symbolic constant
	double Centigrade, Fahrenheit;

	printf("Centigrade  Fahrenheit\n");
	Centigrade = 3.0;
	while(Centigrade < 18.5)		/* starting the while loop	*/
	{						/* start of block			*/
		Fahrenheit = SCALE * Centigrade + ADJUST;
		printf("%9.1fC %9.2fF\n", Centigrade, Fahrenheit);
		Centigrade = Centigrade + 1.0;
	}						/* end of block				*/
	printf("Conversions Finish.\n");

	return 0;
}
