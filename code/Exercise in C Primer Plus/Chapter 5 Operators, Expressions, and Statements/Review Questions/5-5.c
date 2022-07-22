/* Review Questions 5.5.c */

/*
 * 5. Here's an alternative design for Listing 5.9. It appears to simplify the code by replacing
 *    the two scanf() statements in Listing 5.9 with a single scanf() statement. What makes
 *    this design inferior to the original?

#include <stdio.h>
#define S_TO_M 60
int main(void)
{
	int sec, min, left;

	printf("This program converts seconds to minutes and ");
	printf("seconds.\n");
	printf("Just enter the number of seconds.\n");
	printf("Enter 0 to end the program.\n");
	while (sec > 0) {
		scanf("%d", &sec);
		min = sec/S_TO_M;
		left = sec % S_TO_M;
		printf("%d sec is %d min, %d sec. \n", sec, min, left);
		printf("Next input?\n");
	}
	printf("Bye!\n");
	return 0;
}

 */

#include <stdio.h>
#define S_TO_M 60
int main(void)
{
	int sec, min, left;

	printf("This program converts seconds to minutes and ");
	printf("seconds.\n");
	printf("Just enter the number of seconds.\n");
	printf("Enter 0 to end the program.\n");
	scanf("%d", &sec);
	while (sec > 0) {
		min = sec/S_TO_M;
		left = sec % S_TO_M;
		printf("%d sec is %d min, %d sec. \n", sec, min, left);
		printf("Next input?\n");
		scanf("%d", &sec);
	}
	printf("Bye!\n");
	return 0;
}

/*
 5. The main problem lies in the relationship between the test statement (is sec greater
    than 0?) and the scanf() statement that fetches the value of sec. In particular, the first
    time the test is made, the program hasn't had a chance to even get a value for sec, and 
    the comparison will be made to some garbage value that happens to be at that memory
    location; it might or might not be greater than 0. One solution, albet an inelegant
    one, is to initialize sec to, say, 1 so that the test is passed the first time through. This
    uncovers a second problem. When you finally type 0 to halt the problem, sec doesn't 
    get checked until after the loops is finished, and the results for 0 seconds are printed out.    What you really wnat is to have a scanf() statement just before the while test is made.
    You can accomplish that by altering the central part of the problem to read this way:
    scanf("%d", &sec);
    while( sec > 0 ) {
		min = sec/S_TO_M;
		left = sec % S_TO_M;
		printf("%d sec is %d min, %d sec. \n", sec, min, left);
		printf("Next input?\n");
		scanf("%d", &sec);
	}
	The first time through, the scanf() outside the loop is used. Thereafter, the scanf()
    at the end of the loop(and hence just bofore the loop begins again) is used. This is a
    common method for handling problems of this sort, which is why Listing 5.9 used it.
 */
