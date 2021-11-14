/*
 * Exercise 5-1. As written, getint treats a + or - followed by a digit as a
 * valid representation of zero. Fix it to push such a character back on the
 * input.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE  100

/* functions */
int  getch(void);
void ungetch(int);
int  getint(int *);

/* global */
int    buf[BUFSIZE];         /* buffer from ungetch (can handle EOF push back) */
int    bufp = 0;             /* next free position in buf */

int getch(void)              /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)          /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))   /* skip white space */
		;
	if (!isdigit(c) && c != '+' && c != '-') {
		ungetch(c);  /* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		if (!isdigit((c = getch()))) /* sign followed by a digit? */
			return 0; /* not a number */
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	ungetch(c);
	return c;
}

int main(void)
{
	int input, num;

	while ((input = getint(&num)) && input != EOF)
		printf("%i\n", num);
	return 0;
}