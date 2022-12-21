#include <stdio.h>
#include <math.h>

void print_logarithm(double x)
{
	if (x <= 0.0) {
		printf("Positive numbers only, please.\n");
		return;
	}
	printf("The log of x is %f\n", log(x));
}

// int is_even(int x)
// {
// 	if (x % 2 == 0)
// 		return 1;
// 	else
// 		return 0;
// }

int is_even(int x)
{
	return !(x % 2);
}

int main(void)
{
	print_logarithm(2.0);
	int i = 19;

	if (is_even(i)) {
		printf("do something\n");
	} else {
		printf("do some other thing\n");
	}

	return 0;
}
