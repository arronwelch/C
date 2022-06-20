// Review Questions 4-1

// Run Listing 4.1 again, but this time give your first and last name when it asks you for
// your first name. What happens? Why?

// Listing 4.1 The talkback.c Program

// talkback.c -- nosy, information program
#include <stdio.h>
#include <string.h>			// for strlen() prototype
#define DENSITY 62.4		// human density in lbs per su ft

int main(void)
{
	float weight, volume;
	int size, letters;
	char name[40];			// name is an array of 40 chars

	printf("Hi! What's your first name?\n");
	scanf("%s", name);
	printf("%s, what's your weight in pounds?\n", name);
	scanf("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
	printf("Also, your first name has %d letters,\n", letters);
	printf("and we have %d bytes to store it.\n", size);

	return 0;
}

/***********************************
$ gcc 1.c
$ ./a.out

[pass] test input:
$ Lasha 144

[pass] test output:
$ Lasha, what's your weight in pounds?
$ Well, Lasha, your volume is 2.31 cubic feet.
$ Also, your first name has 5 letters,
$ and we have 40 bytes to store it.
***********************************/

/***********************************
[fail] test input:
$ Lasha Lisa

[fail] test output:
$ Lasha, what's your weight in pounds?
$ Well, Lasha, your volume is 0.00 cubic feet. [NOTE]: this is error!!!
$ Also, your first name has 5 letters,
$ and we have 40 bytes to store it.
***********************************/
