/* Programming Exercises 5-5.c */

/*
5.	Change the program addemup.c(Listing 5.13),which found the sum of the first 20
	integers.(If you prefer, you can think of addemup.c as a program that calculates how
	much money you get in 20 days if you receice $1 the first day, $2 the second day, $3 the
	third day, and so on.) Modify the program so that you can tell it interactively how far
	the calculation should proceed. That is, replace the 20 with a variable that is read in.
*/

// Listing 5.13 The addemup.c Program

/* addemup.c -- five kinds of statements */
#include <stdio.h>

int main(void)					/* finds sum of first 20 integers	*/
{
	int count, sum;				/* declaration statement			*/
	int days;

	printf("Enter the number of week days.\n");
	scanf("%d", &days);
	count = 0;					/* assignment statement				*/
	sum = 0;					/* ditto							*/
	while (count++ < days)		/* while							*/
	{
		sum = sum + count;		/* 		statement					*/
		printf("count = %3d, sum = %3d\n", count, sum);	/* function statement				*/
	}

	return 0;					/* return statement					*/
}
