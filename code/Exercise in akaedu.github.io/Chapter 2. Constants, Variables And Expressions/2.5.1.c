#include <stdio.h>

int main(void)
{
	int x = 17, n = 4;
	printf("%d / %d = %d\n", x, n, (int)(x/n + 1.0));
	x = 16, n = 4;
	printf("%d / %d = %d\n", x, n, x/n);
	return 0;
}
