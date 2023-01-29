/* mypow.c */

#include <stdio.h>

double mypow1(double x, int n)
{
	double product = 1;
	while (n--)
	{
		printf(".");
		product *= x;
	}
	return product;
}

double mypow2(double x, int n)
{
	double product = 1;
	if (n % 2 == 0)
	{
		x *= x;
		n /= 2;
		while (n--)
		{
			printf(".");
			product *= x;
		}
	}
	else
	{
		product *= x;
		n--;
		x *= x;
		n /= 2;
		while (n--)
		{
			printf(".");
			product *= x;
		}
	}
	return product;
}

double mypow3(double x, int n)
{
	printf(".");
	if (n == 2)
		return x * x;
	else if (n % 2 == 0)
	{
		double t = mypow3(x, n/2);
		return t * t;
	}
	else
	{
		double t = mypow3(x, n/2);
		return x * t * t;
	}
}

int main(void)
{
	double x = 2;
	int n = 8;
	printf("mypow1(%f, %d) = %f\n", x, n, mypow1(x, n));
	printf("mypow2(%f, %d) = %f\n", x, n, mypow2(x, n));
	printf("mypow3(%f, %d) = %f\n", x, n, mypow3(x, n));

	return 0;
}
