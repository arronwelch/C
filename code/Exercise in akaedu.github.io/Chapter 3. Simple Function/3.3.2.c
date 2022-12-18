#include <stdio.h>

void increment(int x)
{
	x = x + 1;
}

int main(void)
{
	int i = 1, j = 2;
	increment(i); /* i now becomes 2 */
	increment(j); /* j now becomes 3 */
	return 0;
}

/*
 * x is in stack of increment() run time
 * i and j is in stack of main() run time
 */
