/* Multi-dimensional Array */

#include <stdio.h>

int main(void)
{
	int a[3][2] = { 1, 2, 3, 4, 5 }; // Row-major

	int a1[][2] = { {1, 2 },
					{3, 4 },
					{5,   } };

	// C99 Memberwise Initialization
	int a2[3][2] = { [0][1] = 9, [2][1] = 8 };

	// structures nesting array
	struct complex_struct {
		double x, y;
	} a3[4] = { [0].x = 8.0 };

	struct {
		double x, y;
		int count[4];
	} s = { .count[2] = 9 };

	return 0;
}

