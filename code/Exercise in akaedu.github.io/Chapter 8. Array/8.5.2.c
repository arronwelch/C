/* Data-driven Programming */

#include <stdio.h>

void print_day(int day)
{
	char days[8][10] = { "", "Monday", "Tuesday",
						 "Wednesday", "Thursday", "Friday",
						 "Saturday", "Sunday" };

	if (day < 1 || day > 7)
		printf("Illegal day number!\n");
	printf("%s\n", days[day]);
}

int main(void)
{
	print_day(2);

	return 0;
}

/*
 * \0 \0 \0 \0 \0 \0 \0 \0 \0 \0
 * M  o  n  d  a  y  \0 \0 \0 \0
 * T  u  e  s  d  a  y  \0 \0 \0
 * W  e  d  n  e  s  d  a  y  \0
 * T  h  u  r  s  d  a  y  \0 \0
 * F  r  i  d  a  y  \0 \0 \0 \0
 * S  a  t  u  r  d  a  y  \0 \0
 * S  u  n  d  a  y  \0 \0 \0 \0
 */

