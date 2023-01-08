// c progream to print all permutations
// with duplicates allowed

#include <stdio.h>
#define N 4 // total element number
#define M 3 // select element number

void permut(int a[], int offset, int range);
void print(int a[], int range);
void swap(int* x, int* y);

int main(void)
{
	int i, a[N];

	for (i = 0; i < N; i++)
	{
		a[i] = i + 1;
	}
	permut(a, 0, M - 1);
}

void permut(int a[], int offset, int range)
{
	int temp, i = 0;
	if ( offset == range)
	{
		print(a, range);
		return;
	}
	else
	{
		for (i = offset; i <= range; i++)
		{
			swap(a+i, a+offset);
			permut(a, offset + 1, range);
			swap(a+i, a+offset);
		}
	}
}

void print(int a[], int range)
{
	int i;
	for (i = 0; i <= range; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int* x, int* y)
{
	if (x == y)
		return;

	int temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

