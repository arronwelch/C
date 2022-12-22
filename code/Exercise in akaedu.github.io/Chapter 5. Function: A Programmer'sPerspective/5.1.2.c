#include <stdio.h>

void foo(int x, int y)
{
	// Be carefully checkout all Code Path.
	if (x >= 0 || y >= 0) {
		printf("both x and y are positive.\n");
		return;
	} else if (x < 0 || y < 0) {
		printf("both x and y are negetive.\n");
		return;
	}
	printf("x has a different sign from y.\n"); // Dead Code
}

int main(void)
{
	foo(0, 0);
	foo(-1, -1);
	foo(-1, 0);
	return 0;
}
