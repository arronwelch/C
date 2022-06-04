#include <stdio.h>

int main(void)
{
	float age;
	printf("Please enter your age: ");
	scanf("%f", &age);
	printf("the equivalent number of seconds: %f s\n", age*3.156e7);

	return 0;
}
