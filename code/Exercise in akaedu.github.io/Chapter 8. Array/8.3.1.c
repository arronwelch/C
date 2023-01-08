#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int a[N];

void gen_random(int upper_bound)
{
	int i;

	time_t tmp, seconds;
	srand(tmp = time(&seconds));
	printf("Seconds since January 1, 1970 = %ld %ld\n", seconds, tmp);
	for (i = 0; i < N; i++)
		a[i] = rand() % upper_bound;
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
	int i, histogram[10] = {0};
	int max = 0;

	gen_random(10);

	for (i = 0; i < N; i++) // Single Pass
	{
		histogram[a[i]]++;
		if (histogram[a[i]] > max)
			max = histogram[a[i]];
	}

	print_random();
	printf("\n");

	for (i = 0; i < 10; i++)
		printf("%d ", i);
	printf("\n");

	while(max--)
	{
		for (i = 0; i < 10; i++)
		{
			if (histogram[i]-- > 0)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}

	return 0;
}
