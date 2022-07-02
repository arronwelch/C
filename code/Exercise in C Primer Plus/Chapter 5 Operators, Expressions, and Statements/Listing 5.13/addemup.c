// Listing 5.13 The addemup.c Program

/* addemup.c -- five kinds of statements */
#include <stdio.h>

int main(void)					/* finds sum of first 20 integers	*/
{
	int count, sum;				/* declaration statement			*/

	count = 0;					/* assignment statement				*/
	sum = 0;					/* ditto							*/
	while (count++ < 20)		/* while							*/
	{
		sum = sum + count;		/* 		statement					*/
		printf("count = %3d, sum = %3d\n", count, sum);	/* function statement				*/
	}

	return 0;					/* return statement					*/
}
