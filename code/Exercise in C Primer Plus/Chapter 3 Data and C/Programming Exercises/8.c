#include <stdio.h>

int main(void)
{
	float cups;
	printf("Please enter a volume in cups: ");
	scanf("%f", &cups);
	printf("the equivalent in pins: %f\n", cups / 2.0);
	printf("the equivalent in ounces: %f\n", cups * 8.0);
	printf("the equivalent in tablespoons: %f\n", cups * 16.0);
	printf("the equivalent in teaspoons: %f\n", cups * 48.0);
	
	return 0;
}
