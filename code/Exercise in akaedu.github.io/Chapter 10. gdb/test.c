#include <stdio.h>

int main(void)
{
	int i;
	char str[6] = "hello";
	char reverse_str[6] = "";

	printf("%s\n", str);
	for (i = 0; i < 5; i++)
		reverse_str[4-i] = str[i]; // string first char is '\0'
	printf("%s\n", reverse_str);

	return 0;
}
