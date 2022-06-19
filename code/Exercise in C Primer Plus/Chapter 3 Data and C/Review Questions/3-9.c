/* Review Questions 3.9 */

// Suppose that ch is a type char variable. Show how to assign the carriage-return character
// to ch by using an escape sequence, a decimal value, an octal character constant, and a
// hex character constant.(Assume ASCII code values.)

#include <stdio.h>

int main(void)
{
	char ch;

	ch = '\n';
	ch = 10;
	ch = '\012';	// \0oo		Octal value.(o represents an octal digit.)
	ch = '\x0a';	// \xhh		Hexadecimal value.(h represents a hexadecimal digit.)

	printf("%d\n", ch);

	ch = '\r';
	ch = 13;
	ch = '\015';
	ch = '\xd';
	
	printf("%d\n", ch);

	return 0;
}
