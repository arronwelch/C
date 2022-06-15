#include <stdio.h>		/* don't forget this 		*/
#define B "booboo"		/* add #, quotes			*/
#define X 10			/* add #					*/

int main(void)			/* instead of main(int)		*/
{
	int age;
	int xp;				/* declare all variables	*/
	char name[BUFSIZ];	/* make into an array		*/

	printf("Please enter your first name.\n"); /* \n for readability */
	scanf("%s", name);
	printf("All right, %s, what's your age?\n", name);	/* %s for string */
	scanf("%d", &age);		/* %d, not %f, &age, not age	*/
	xp = age + X;
	printf("That's a %s! You must be at least %d.\n", B, xp);

	return 0;				/* return, not rerun			*/
}
