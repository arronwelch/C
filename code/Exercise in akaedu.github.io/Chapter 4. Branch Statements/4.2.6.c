#include <stdio.h>

void print_x(int x)
{
	printf("%d\n", x % 10);
	printf("%d\n", x / 10);
}

int main(void)
{
	int x = 14;
	printf("%d", x % 10);
	printf("%d\n", x / 10);
	print_x(14);
	return 0;
}
