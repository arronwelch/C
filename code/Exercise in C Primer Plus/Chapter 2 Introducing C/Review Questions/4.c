// Review Questions 2.4

// Indiana Sloth has prepared the following program and brought it to you for approval.
// Please help him out.

// 1 include studio.h
// 2 int main{void} /* this prints the number of weeks in a year /*
// 3 (
// 4 int s
// 5
// 6 s := 56;
// 7 print(There are s weeks in a year.);
// 8 return 0;

// Line 1: Begin the line with a #; spell the file stdio.h;place the filename within angle
// brackets.

// Line 2: Use (), not {}; end the comment with */, not /*.

// Line 3: Use {, not (.

// Line 4: Complete the statement with a semicolon.

// Line 5: Indiana got this one(the blank line) right!

// Line 6: Use =, not := for assignment. (Apparently, Indiana knows a little Pascal.) Use 52,
// not 56, weeks per year.

// Line 7: Should be
// printf("There are %d weeks in a year.\n", s);

// Line 8: Right.

// Line 9: There isn't a line 9, but there be, and it should consist of the closing
// brace, }.

// Here's how the code looks after these changes:

#include <stdio.h>

int main(void) /* this prints the number of weeks in a year */
{
	int s;

	s = 52;
	printf("There are %d weeks in a year.\n", s);
	return 0;
}
