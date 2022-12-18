#include <stdio.h>

void newline(void)
{
	printf("\n");
}

void threeline(void)
{
	newline();
	newline();
	newline();
}

int main(void)
{
	printf("Three Line:\n");
	threeline();
	printf("Another three lines.\n");
	threeline();
	return 0;
}
