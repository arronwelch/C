#include <stdio.h>
#include <stdlib.h>
#define N 100000

int a[N];

void gen_random(int lower_bound, int upper_bound)
{
	int i;
	for (i = 0; i < N; i++)
		a[i] = rand() % (upper_bound - lower_bound) + lower_bound;
}

int howmany(int value)
{
	int count = 0, i;
	for (i = 0; i < N; i++)
		if (a[i] == value)
			++count;
	return count;
}

void print_random()
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(void)
{
	int i;
	int lower_bound = 10, upper_bound = 21;

	gen_random(lower_bound, upper_bound);
	printf("value\t how many\n");
	for (i = lower_bound; i < upper_bound; i++)
		printf("%d\t%d\n", i, howmany(i));

	//print_random();
	return 0;
}
