#include <stdio.h>

int main(void)
{
	float num;
	printf("Please enter an amount of water,in quarts: ");
	scanf("%f", &num);
	printf("the number of water molecules is: %f\n", num * 950.0 / 3e-23);

	return 0;
}
