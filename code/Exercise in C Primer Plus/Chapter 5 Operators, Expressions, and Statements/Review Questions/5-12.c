/* Review Questions 5-12.c */

/*
12.Construct statements that do the following(or, in other terms, have the following side effects):
	a. Increase the variable x by 10.
	b. Increase the variable x by 1.
	c. Assign twice the sum of a and b to c.
	d. Assign a plus twice b to c.
*/

#include <stdio.h>
int main(void)
{
	int x = 0, a = 1, b = 2, c =3;

	printf("x = %d\n",x);
	printf("a. Increase the variable x by 10.\n");
	x += 10;
	printf("x = %d\n",x);

	printf("b. Increase the variable x by 1.\n");
	x++;
	printf("x = %d\n",x);

	printf("a = %d, b = %d, c = %d\n",a, b, c);
	printf("c. Assign twice the sum of a and b to c.\n");
	c = 2 * (a + b);
	printf("a = %d, b = %d, c = %d\n",a, b, c);

	printf("d. Assign a plus twice b to c.\n");
	c = a + 2 * b;
	printf("a = %d, b = %d, c = %d\n",a, b, c);
	
	return 0;
}

/*
a. x = x + 10; or x += 10;
b. x++; or ++x; or x = x + 1; or x += 1;
c. c = 2 * (a + b);
d. c = a + 2 * b;
*/
