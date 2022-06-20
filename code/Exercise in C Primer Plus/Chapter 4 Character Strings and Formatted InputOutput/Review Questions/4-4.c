/* Review Questions 4.4 */

// It's find the error time!

// 1 define B booboo
// 2 define X 10
// 3 main(int)
// 4 {
// 5	int age;
// 6	char name;
// 7	printf("Please enter your first name.");
// 8	scanf("%s", name);
// 9	printf("All right, %c, what's your age?\n", name);
// 10	scanf("%f", age);
// 11	xp = age + X;
// 12	printf("That's a %s! You must be at least %d.\n", B, xp);
// 13	rerun 0;
// 14 }

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
