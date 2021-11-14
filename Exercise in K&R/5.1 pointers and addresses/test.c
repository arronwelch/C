
#include <stdio.h>
#include <ctype.h>

#define SIZE 5

void swap(int *px, int *py);

int main(void)
{
    int x = 1, y = 2, z[10];
    int *ip;   /* ip is a pointer to int type variable[mnemonic] */

    swap(&x,&y);

    ip = &x;   /* ip now points to x */
    printf("ip = %p\n",ip);//ip = 000000000061FE0C (address，64bit)
    y = *ip;   /* y is now 1 */
    printf("y = %d\n",y);
    *ip = 0;   /* x is now 0 */
    printf("x = %d\n",x);    
    ip = &z[0]; /* ip now points to int array z's first address(z[0]) */

    z[3] = 3;
    printf("z[3] = %d\n",z[3]);
    printf("*(ip+3) = %d\n",*(ip+3));

    *ip = *ip + 10;

    y = *ip + 1;

    *ip += 1;
    
    ++*ip;

    (*ip)++;// the parentheses are necessary in this last example,
            // because unary operators like * and ++ associate right to left  [ left<--right ]
    
    int *iq;
    iq = ip;
    printf("*(iq+3) = %d\n",*(iq+3));

    int n, array[SIZE], getint(int *);/* declaration */

    for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++) /* fills an array with integers by calls to getint */
        ;

    for(n = 0; n < SIZE ; n++) /* print the array */
        printf("array[%d] = %d ",n,array[n]);

    return 0;
}

/* swap： interchange *px and *py 
 * int a = 0, b = 1;
 * swap(&a,&b);
 */
void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

#define BUFSIZE 100

int getch(void);/* declaration */
void ungetch(int);/* declaration */

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void)    /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* get a (possibly pushed-back) character */
{
    if(bufp >= BUFSIZE)
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

	if (!isdigit(c) && c != '+' && c != '-') 
    {
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