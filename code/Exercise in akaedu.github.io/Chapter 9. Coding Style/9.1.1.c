#include <stdio.h>

int main(void)
{
	printf("while (1);\n");
	printf("i = i + 1; ++i; !(i < 1); -x; &a[1];\n");
	printf("s.a; foo(arg1); a[i];\n");
	printf("for (i = 1; i < 10; i++); foo(arg1, arg2);\n");
	printf("for (i=1; i<10; i++); distance = sqrt(x*x + y*y);\n");
	/*
	 * 24 rows, 80 column;
	 *
	 * if (sqrt(x*x + y*y) > 5.0 && x < 0.0 && y > 0.0)
	 *
	 * foo(sqrt(x*x + y*y), a[i-1] + b[i-1] + c[i-1])
	 */

	printf("This is such a long sentence that "
	       "it cannot be held within a line.\n");

	int	a, b;
	double	c;

	/*
	 * if (...) {
	 * 	;
	 * } else if (...) {
	 *	;
	 * }
	 *
	 * int foo(int a, int b)
	 * {
	 * 	;
	 * }
	 *
	 * switch (c) {
	 * case 'A':
	 *	;
	 *	break;
	 * case 'B':
	 *	;
	 *	break;
	 * default:
	 *	;
	 *	break;
	 * }
	 *
	 */

	/*
	 * Multi-line comment
	 */

	/**************\
	* Multi-line   *
	* comment      *
	\***************/

	return 0;
}
