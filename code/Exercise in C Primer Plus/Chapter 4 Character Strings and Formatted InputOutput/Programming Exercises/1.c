/* Programming Exercises 4-1 */

// Write a program that asks for your first name, your last name, and then prints the names
// in the format last, first.

#include <stdio.h>

int main(void)
{
	char first[BUFSIZ], last[BUFSIZ];
	printf("Please enter your first and last name:\n");
	scanf("%s %s", first, last);
	printf("Hi! %s, %s.Have a good day!\n", last, first);

	return 0;
}
