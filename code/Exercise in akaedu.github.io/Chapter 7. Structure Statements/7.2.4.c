#include <stdio.h>

struct rational {
	int s, m;
};

void print_rational(struct rational z)
{
	if (z.m < 0)
	{
		z.s = -z.s;
		z.m = -z.m;
	}
	if (z.s == 0 || z.m == 1)
		printf("%d\n", z.s);
	else
		printf("%d/%d\n", z.s, z.m);
}

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	else
	{
		return gcd(b, a%b);
	}
}

struct rational gcd_rational(struct rational z)
{
	if (z.s == 0)
		return z;

	int t = gcd(z.s, z.m);
//	printf("t=%d\n", t);
	if (t != 1)
	{
		z.m = z.m / t;
		z.s = z.s / t;
	}
	return z;
}

struct rational make_rational(int s, int m)
{
	struct rational z;
	z.s = s;
	z.m = m;
	return z;
}

struct rational add_rational(struct rational a, struct rational b)
{
	if (a.m == b.m)
	{
		a.s = a.s + b.s;
	}
	else
	{
		a.s = a.s * b.m;
		b.s = b.s * a.m;
		a.s = a.s + b.s;
		a.m = a.m * b.m;
	}
	return gcd_rational(a);
}

struct rational sub_rational(struct rational a, struct rational b)
{
	if (a.m == b.m)
	{
		a.s = a.s - b.s;
	}
	else
	{
		a.s = a.s * b.m;
		b.s = b.s * a.m;
		a.s = a.s - b.s;
		a.m = a.m * b.m;
	}
	return gcd_rational(a);
}

struct rational mul_rational(struct rational a, struct rational b)
{
	a.s = a.s * b.s;
	a.m = a.m * a.m;
	return gcd_rational(a);
}

struct rational div_rational(struct rational a, struct rational b)
{
	a.s = a.s * b.m;
	a.m = a.m * b.s;
	return gcd_rational(a);
}

int main(void)
{
	struct rational a = make_rational(1, 8); /* a=1/8 */
	struct rational b = make_rational(-1, 8); /* b=-1/8 */
//	print_rational(a);
//	print_rational(b);
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));
	return 0;
}
