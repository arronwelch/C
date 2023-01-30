/* print_backward.c */

#include <stdio.h>
#define LEN 3

char buf[LEN] = { 'a', 'b', 'c' };

void print_backward(int pos)
{
	if (pos == LEN)
		return;
	print_backward(pos+1);
	putchar(buf[pos]);
}

int main(void)
{
	print_backward(0);
	putchar('\n');

	return 0;
}
