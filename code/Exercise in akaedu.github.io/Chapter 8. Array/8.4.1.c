// c-string
#include <stdio.h>

int main(void)
{
	int i;
	char c = "Hello, world.\n"[0]; // Null-terminated String
	printf("%c\n", c);

	// "Hello, world.\n"[0] = 'A'; // not allowed

	char str[10] = "Hello";
	printf("%s\n", str);

	char str1[10] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	printf("%s\n", str1);

	char str2[10] = "Hello, world.\n"; // initial string is longer than char array.
	printf("%s\n", str2);

	char str3[] = "Hello, world.\n";
	printf("%s\n", str3);

	return 0;
}
