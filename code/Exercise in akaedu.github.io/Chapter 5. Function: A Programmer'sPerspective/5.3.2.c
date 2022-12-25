#include <stdio.h>

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	else {
		return gcd(b, a % b);
	}
}

int fib(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else {
		return fib(n-1)+fib(n-2);
	}
}

int main(void)
{
	printf("%d\n", gcd(-64, 12));
	printf("%d\n", fib(5));
	return 0;
}
