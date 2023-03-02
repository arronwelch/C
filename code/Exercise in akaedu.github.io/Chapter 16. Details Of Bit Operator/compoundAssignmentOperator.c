/*
 * Compound Assignment Operator
 * Side Effect
 */

#include <stdio.h>

int foo(void)
{
	static int i = -1;
	i++;
	printf("%d\n", i);
	return i;
}

int main(void)
{
	int a[3] = {0};
	for (int i = 0; i < 3; i++)
		printf("a[%d] = %d\n", i, a[i]);

	printf("--------------\n");
	a[foo()] += 1;
	printf("--------------\n");
	a[foo()] = a[foo()] + 1;
	printf("--------------\n");

	for (int i = 0; i < 3; i++)
		printf("a[%d] = %d\n", i, a[i]);

	return 0;
}
