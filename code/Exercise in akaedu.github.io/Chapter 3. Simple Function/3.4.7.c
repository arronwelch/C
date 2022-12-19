#include <stdio.h>

void test_func(void)
{
//	print_time(0, 45);
}

int main(void)
{
	void print_time(int, int);
	print_time(23, 59);
	return 0;
}

void print_time(int hour, int minute)
{
	printf("%d:%d\n", hour, minute);
}
