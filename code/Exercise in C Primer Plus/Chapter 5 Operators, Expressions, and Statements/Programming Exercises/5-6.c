/* Programming Exercises 5-6.c */

/*
6.	Now modify the program of Programming Exercise 5 so that it computes the sum of the
	squares of the integers.(If you prefer,how much money you receive if you get $1 the
	first day, $4 the second day, $9 the third day, and so on.This look like a much better
	deal!) C doesn't have a squaring function, but you can use the fact that the sequare of n is
	n * n.
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
		sum = sum + count * count;		/* 		statement					*/
		printf("count = %3d, sum = %3d\n", count, sum);	/* function statement				*/
	}

	return 0;					/* return statement					*/
}
