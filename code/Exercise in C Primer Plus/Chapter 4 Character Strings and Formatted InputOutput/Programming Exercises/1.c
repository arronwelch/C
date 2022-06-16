#include <stdio.h>

int main(void)
{
	char first[BUFSIZ], last[BUFSIZ];
	printf("Please input your first and last name:\n");
	scanf("%s %s", first, last);
	printf("Hi! %s, %s.Have a good day!\n", last, first);

	return 0;
}
