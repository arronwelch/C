// Review Questions 2.8

// Consider the following program:
// #include <stdio.h>
// int main(void)
// {
//		int a, b;

//		a = 5;
//		b = 2;	/* line 7 */
//		b = a;	/* line 8 */
//		a = b;	/* line 9 */
//		printf("%d %d\n", b, a);
//		return 0;
// }

// What is the program state after line 7?Line 8?Line 9?

// Line 7: a = 5, b = 2;
// Line 8: a = 5, b = 5;
// Line 9: a = 5, b = 5;

// After line 7, a is 5 and b is 2.
// After line 8, both a and b are 5.
// After line 9, both a and b are stil 5.
// (Note that a can't be 2 because by the time you say a = b;, b has already
// been changed to 5.)
