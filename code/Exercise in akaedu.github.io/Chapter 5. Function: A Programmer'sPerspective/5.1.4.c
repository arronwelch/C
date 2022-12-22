#include <stdio.h>

int absolute_value(int x)
{
	if (x < 0) {
		return -x;
	} else if (x > 0) {
		return x;
	}
}

int main(void)
{
	printf("%d\n", absolute_value(1));
	printf("%d\n", absolute_value(0));
	return 0;
}
