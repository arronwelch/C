#include <stdio.h>

int factorial(int n)
{
	if (n == 0)
		return 1;
	else {
		int recurse = factorial(n-1);
		int result = n * recurse;
		return result;
	}
}

int main(void)
{
	int result = factorial(3);
	printf("%d\n", result);
	return 0;
}
