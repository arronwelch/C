#include <stdio.h>

int main(void)
{
	printf("test Alert escape sequences:\a\n");//Alert(ANSI C)
	printf("test Backspace:\babc\n");//Backspace
	printf("test Form fedd:\fabc\n");//Form feed
	printf("test Newlien:\nabc\n");//Newline
	printf("test Carriage return:\rabc\n");//Carriage return
	printf("test Horizontal tab:\tabc\n");//Horizontal tab
	printf("test Vertical tab:\vabc\n");//Vertical tab
	printf("test Backslash(\\):\\abc\n");//Backslash(\)
	printf("test Single quote(\'):\'abc\n");//Single quote(')
	printf("test Double quote(\"):\"abc\n");//Double quote(")
	printf("test Question mark(\?):\?abc\n");//Question mark(?)
	printf("test Octal value 63:\077 abc\n");//Octal value.(o represents an octal digit.)
	printf("test Hexadecimal value 63:\x3f abc\n");//Hexadecimal value.(h represents a hexadecimal digit.)
	printf("%d\n",'?');

	return 0;
}
