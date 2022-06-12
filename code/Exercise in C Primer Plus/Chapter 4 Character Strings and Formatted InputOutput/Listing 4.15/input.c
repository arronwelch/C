// Listing 4.15 The input.c Program
// input.c -- when to use &

#include <stdio.h>

int main(void)
{
	int age;		// variable
	float asserts;	// variable
	char pet[30];	// string

	printf("Enter your age, asserts, and favorite pet.\n");
	scanf("%d %f", &age, &asserts);	// use the & here
	scanf("%s", pet);				// no & for char array
	printf("%d $%.2f %s\n", age, asserts, pet);

	return 0;
}
