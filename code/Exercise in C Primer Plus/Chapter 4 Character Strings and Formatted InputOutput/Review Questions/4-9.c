/* Review Questions 4.9 */

// For each of the following input lines, provide a scanf() statement to read it. Also
// declare any variables or arrays used in the statement.

// a. 101
// b. 22.32 8.34E-09
// c. linguini
// d. catch 22
// e. catch 22 (but skip over catch)

#include <stdio.h>

int main(void)
{
	int a = 1;
	scanf("%d", &a);
	printf("a:%d\n", a);

	float b1 = 2.1, b2 = 2.2;
	scanf("%f %E", &b1, &b2);
	printf("b:%.2f %.2E\n", b1, b2);
	/*
	 * (Note: For input, e, f, and g can be used interchangeably. Also, for all but %c, it
	 * makes no difference if you leave spaces between the conversion specifiers.)
	 */

	char str3[BUFSIZ];
	scanf("%s", str3);
	printf("c:%s\n", str3);

	char str4[BUFSIZ];
	int d4;
	scanf("%s %d", str4, &d4);
	printf("d:%s %d\n", str4, d4);

	char str5[BUFSIZ];
	int e5;
	scanf("%*s %d", &e5);
	printf("e:%d\n", e5);

	return 0;
}
