#include <stdio.h>

int count[4];

struct complex_struct {
	double x, y;
} a[4];

struct {
	double x, y;
	int count[4];
} s;

int main(void)
{
	count[0] = 7;
	count[1] = count[0] * 2;
	++count[2];

	int i = 1;
	count[i] = count[i+1];

	int count1[4] = { 3, 2, }; // { 3, 2, 0, 0 }
	int count2[] = { 3, 2, 1, }; // { 3, 2, 1 }
	int count3[4] = { [2] = 3 }; // C99 Memberwise Initialization { 0, 0, 3, 0 }

	int count4[4] = { 3, 2, }, i1;

	for (i1 = 0; i1 < 4; i1++) // Traversal
		printf("count4[%d]=%d\n", i1, count4[i1]);

	int a[5] = { 4, 3, 2, 1 };
	int b[5] = a; // array initializer must be an initializer list or wide string literal
	a = b; // array type 'int[5]' is not assignable

	return 0;
}
