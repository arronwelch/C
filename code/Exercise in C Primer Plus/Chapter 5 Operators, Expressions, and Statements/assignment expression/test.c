// what about the ones with = signs?
// Those expressions simply have the same value
// that the variable to the left of the = sign receives.

#include <stdio.h>

int main(void)
{
	int c;
	int next_value = 6 + (c = 3 + 8);// it is perfectly legal(but ill-advised) in C
	printf("next value = %d\n", next_value);

	return 0;
}
