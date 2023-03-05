/*
 * Side Effect and Sequence Point
 */

#include <stdio.h>

int f(void)
{
	printf("f() return 1\n");
	return 1;
}

int g(void)
{
	printf("g() return 2\n");
	return 2;
}

void foo(int x, int y)
{
	printf("x = %d, y = %d\n", x, y);
}

int main(void)
{
	foo(f(), g());

	int a = 0;
	a = (++a)+(++a)+(++a)+(++a); // multiple unsequenced modifications to 'a' [-Wunsequenced]
	printf("a = %d\n", a);

	int i = 1;
	int b[5] = {0};
	b[i++] = i;
	printf("b[%d] = %d\n", i-1, b[i-1]); // unsequenced modification and access to 'i' [-Wunsequenced]

	return 0;
}
