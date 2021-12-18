
/* Exercise 5-6:
 * Rewrite appropriate programs from earlier chapters and exercises with pointers 
 * instead of array indexing.Good possibilities include getline(Chapters 1 and 4),atoi,itoa,
 * and their variants (Chapters 2,3, and 4), reverse (Chapter 3),and strindex and getop (Chapter 4).
 */

#include <stdio.h>
#include <string.h>

#define MAXLIM 1000 /* maximum input line length */

int getline(char *str,int lim);
int atoi(char *str);
void reverse(char *s);
void itoa(int n,char *str);

int main(void)
{
    char str[MAXLIM];
    int length;
    length = getline(str,MAXLIM);
    printf("%s:%d\n",str,length);
    printf("atoi(str) = %d\n",length = atoi(str));
    printf("itoa(length) = %s\n",itoa(length));

    return 0;
}

/* getline: version in pointers read a line into str, return length */
int getline(char *str,int lim)
{
    int c, i;

    for (i = 0;i <lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *(str+i) = c;
    if (c == '\n')
    {
        *(str+i) = c;
        ++i;
    }
    *(str+i) = '\0';
    return i;
}

int atoi(char *str)
{
    int i,n;

    n = 0;
    for (i = 0; *(str+i) >= '0' && *(str+i) <= '9';++i)
        n = 10 * n + (*(str+i) - '0');
    return n;
}

/* reverse: reverse string s in place */
void reverse(char *s)
{
    int c,i,j;
    
    for (i = 0,j = strlen(s) - 1;i<j;i++,j--)
        c = *(s+i),*(s+i) = *(s+j),*(s+j) = c;
}

void itoa(int n,char *str)
{
    int i, sign;
    if ( (sign = n) < 0) /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do /* generate digits in reverse order */
    {
        *(str+i) = n % 10 + '0'; /* get next digit */
        ++i;
    }
    while( (n /= 10) > 0); /* delete it */
    if ( sign < 0)
        *(str + i) = '-';
    ++i;
    *(str + i) = '\0';
    reverse(str);
}

