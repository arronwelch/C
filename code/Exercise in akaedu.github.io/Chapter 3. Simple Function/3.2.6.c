#include <stdio.h>

//void newline(void);
//void threeline(void);

int main(void)
{
	printf("Three Line:\n");
	threeline();
	printf("Another three lines.\n");
	threeline();
	return 0;
}

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

