#include <stdio.h>

void move_array(int* a, int *b, int size)
{
	for (int i = 0; i < size; i++)
		b[i] = a[i];
//	int c[size] = { 0 };
}

void print_array(int* a, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(void)
{
	const int size = 5;
	int a[size] = { 1, 2, 3, 4, 5 };
	int b[size] = { 0 };
	move_array(a, b, size);
	print_array(b, size);

	return 0;
}
