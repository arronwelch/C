// Listing 4.7 The width.c Program
/* width.c -- field widths */

#include <stdio.h>
#define PAGES 959

int main(void)
{
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);// A wider field will be used if the printed number or string won't fit in the field
	printf("*%10d*\n", PAGES);// The minimum field width.
	printf("*%-10d*\n", PAGES);// it is printed begining at the left of the field

	return 0;
}
