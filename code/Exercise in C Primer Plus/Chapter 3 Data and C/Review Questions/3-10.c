/* Review Questions 3.10 */

// Correct this silly program.(The / in C means division.)

// 0
// 1 void main(int)	/ this program is perfect /
// 2 {
// 3	cows, legs integer;
// 4	printf("How many cow legs did you count?\n);
// 5	scanf("%c", legs);
// 6	cows = legs / 4;
// 7	printf("That implies there are %f cows.\n", cows);
// 8 }

#include <stdio.h>

int main(void)		/* this program is perfect */
{
	int cows, legs;
	printf("How many cow legs did you count?\n");
	scanf("%d", &legs);
	cows = legs / 4;
	printf("That implies there are %d cows.\n", cows);

	return 0;
}

// Line 0: Should have #include <stdio.h>.
// Line 1: Use /* and */ or else //
// Line 3: int cows, legs;
// Line 4: count?\n");
// Line 5: %d, not %c; replace legs with &legs
// Line 7: %d, not %f
// Also, add a return statement.
// Here's one correct version:
