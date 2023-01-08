#include <stdio.h>
#define N 3

int a[N];

void print()
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int i, int sub)
{
	if (i == sub)
		return;
	int temp;
	temp = a[sub];
	a[sub] = a[i];
	a[i] = temp;
}

void permutation(int sub)
{
	int temp, i = 0;
	if ( sub == N - 1)
	{
		print();
		return;
	}
	else
	{
		for (i = sub; i < N; i++)
		{
			swap(i, sub);
			permutation(sub + 1);
			swap(i, sub);
		}
	}
}

int main(void)
{
	int i;
	for (i = 0; i < N; i++)
	{
		a[i] = i + 1;
	}
	permutation(0);
}
