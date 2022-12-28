#include <stdio.h>

int factorial(int n)
{
	int result = 1;
	int i;
	for(i = 1; i <= n; ++i)
		result = result * i;
	return result;
}

int main(void)
{
	printf("%d\n", factorial(3));
	return 0;
}
