/* Programming Exercises 4.6 */

// Write a program that requests the user's first name and then the user's last name. Have
// it print the entered names on one line and the number of letters in each name on the
// following line. Align each letter count with the end of the corresponding name, as in the
// follwing:

// Melissa Honeybee
//       7        8

// Next, have it print the same information, but with the counts aligned with the beginning
// of each name.

// Melissa Honeybee
// 7       8

#include <stdio.h>
#include <string.h>

int main(void)
{
	char first[BUFSIZ], last[BUFSIZ];
	int flen, llen;

	printf("Please enter your first name:\n");
	scanf("%s", first);
	printf("Please enter your last name:\n");
	scanf("%s", last);

	flen = strlen(first);
	llen = strlen(last);

	printf("%s %s\n", first, last);
	printf("%*d %*d\n", flen, flen, llen, llen);

	printf("%s %s\n", first, last);
	printf("%-*d %-*d\n", flen, flen, llen, llen);

	return 0;
}
