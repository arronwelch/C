/* Review Questions 3.5 */

// Dottie Cawm has concocted an error-laden program. Help her find the mistakes.

// 1 include <stdio.h>
// 2 main
// 3 (
// 4  float g; h;
// 5  float tax, rate;
// 6
// 7  g = e21;
// 8  tax = rate*g;
// 9 )

// Line 1: Should be #include <stdio.h>.
// Line 2: Should be int main(void).
// Line 3: Use {, not (.
// Line 4: Should be a comma, not a semicolon, between g and h.
// Line 5: Fine.
// Line 6: (the blank line) Fine.
// Line 7: There should be at least one digit before the e. Either 1e21 or 1.0e21 is okay,
//         although rather large.
// Line 8: Fine, at least in terms of syntax.
// Line 9: Use }, not ).

// Missing lines: First,rate is never assigned a value. Second, the variable h is never used.
// Also, the program never informs you of the results of its calculation. None of these errors
// will stop the program from running (although you might be given a warning about the unused 
// variable), but they do detract from its already limited usefulness. Also, there should be a 
// return statement at the end.

// Here is one possible correct version:

#include <stdio.h>

int main(void)
{
	float g, h;
	float tax, rate;

	rate = 0.08;
	g = 1.0e5;
	tax = rate * g;
	h = g + tax;

	printf("You owe $%f plus $%f in taxes for a total of $%f.\n", g, tax, h);

	return 0;
}
