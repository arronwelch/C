#include <stdio.h>

int main(void)
{
	_Bool boolType;
	boolType = 1 + 1 > 2;
	printf(" 1 + 1 > 2 ? : %s\n", boolType ? "Yes" : "No");

	return 0;
}
