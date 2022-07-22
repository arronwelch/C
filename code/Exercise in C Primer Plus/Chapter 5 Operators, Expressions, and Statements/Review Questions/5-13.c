/* Review Questions 5-13.c */

/*
13. Construct statements that do the following:
	a. Decrease the variable x by 1;
	b. Assign to m the remainder of n divided by k;
	c. Divide q by b minus a and assign the result to p.
	d. Assign to x the result of dividing the sum of a and b by the product of c and d.
*/

#include <stdio.h>

int main(void)
{
	int x = 0;

	int m = 1;
	int n = 2;
	int k = 3;

	int q = 4;
	int b = 5;
	int a = 6;
	int p = 7;

	int c = 8;
	int d = 9;

	printf("x = %d\n", x);
	printf("a. Decrease the variable x by 1.\n");
	x--;
	printf("x = %d\n", x);

	printf("m = %d, n = %d, k = %d\n", m, n, k);
	printf("b. Assigns to m the remainder of n divided by k.\n");
	m = n % k;
	printf("m = %d, n = %d, k = %d\n", m, n, k);

	printf("c. Divide q by b minus a and assign the result to p.\n");
	printf("q = %d, b = %d, a = %d, p = %d\n", q, b, a, p);
	p = q / (b - a);
	printf("q = %d, b = %d, a = %d, p = %d\n", q, b, a, p);

	printf("d. Assign to x the result of dividing the sum of a and b by the product of c and d.\n");
	printf("x = %d, a = %d, b = %d, c = %d, d = %d\n", x, a, b, c, d);
	x = (a + b)/(c * d);
	printf("x = %d, a = %d, b = %d, c = %d, d = %d\n", x, a, b, c, d);

	return 0;
}

/*
a. x--; or --x; or x = x - 1; or x -= 1;
b. m = n % k;
c. p = q / (b - a);
d. x = (a + b)/(c * d);
*/
