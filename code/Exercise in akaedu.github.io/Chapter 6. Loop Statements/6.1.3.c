#include <stdio.h>

int gcd(int a, int b)
{
	while (a % b != 0)
	{
		b = a % b;
		a = b;
	}
	return b;
}

int fib(int n)
{
	if (n == 0 || n == 1)
		return 1;

	int last = 1;
	int nextToLast = 1;
	int answer = 2;
	for ( int i=2; i<=n; i++) {
		answer = last + nextToLast;
		nextToLast = last;
		last = answer;
	}
	return answer;
}

int main(void)
{
	printf("%d\n", gcd(-64, 12));
	printf("%d\n", fib(5));
	return 0;
}
