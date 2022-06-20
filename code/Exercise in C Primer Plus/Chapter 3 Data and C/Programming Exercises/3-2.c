/* Programming Exercises 3.2  */

// Write a program that asks you to enter an ASCII code value, such as 66, and then prints
// the character having that ASCII code.

#include <stdio.h>

int main(void)
{
	int ch;

	printf("Please enter an ASCII code value:\n");
	scanf("%d", &ch);

	printf("The character is \'%c\'\n", ch);

	return 0;
}
