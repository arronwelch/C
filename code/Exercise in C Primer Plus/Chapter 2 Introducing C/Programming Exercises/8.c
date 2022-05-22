#include <stdio.h>
void one_three(void);
int main(void)
{
	printf("starting now:\n");
	one_three();
	printf("done!\n");

	return 0;
}
void one_three(void)
{
	void two(void);
	printf("one\n");
	two();
	printf("three\n");
}
void two(void)
{
	printf("two\n");
}
