
/* {test input}
<<auto[ENTER]
<<auto[ENTER]
<<while[ENTER]
<<while[ENTER] 
<<while[ENTER]
<<void[ENTER]
<<[CTRL+C]
>>   2 auto
>>   1 void
>>   3 while
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEYS sizeof(keytab) / sizeof (keytab[0])

/* third way with initializers */
struct key
{
    char *word;
    int count;
} keytab[] =
    {
        "auto", 0,
        "break", 0,
        "case", 0,
        "char", 0,
        "const", 0,
        "continue", 0,
        "default", 0,
        /* ... */
        "unsigned", 0,
        "void", 0,
        "volatile", 0,
        "while", 0};

#define MAXWORD 100

int getword(char *, int);
int mbinsearch(char *, struct key *, int);

/* count C keywords */
int main(void)
{
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != '$')/* use '$' terminate input */
        if (isalpha(word[0]))
            if ((n = mbinsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;

    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);

    return 0;
}

int mbinsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, d, comment(void), getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '_' || c == '#') /* alphanumeric characters and underscores */
    {
        for (; --lim > 0; w++)
            if (!isalnum(*w = getch()) && *w != '_')
            {
                ungetch(*w);
                break;
            }
    }
    else if (c == '\'' || c == '"') /* string constants */
    {
        for (; --lim > 0; w++)
            if ((*w = getch()) == '\\')
                *++w = getch();
            else if (*w == c)
            {
                w++;
                break;
            }
            else if ( *w == EOF)
                break;
    }
    else if ( c == '/')
        if ( (d = getch()) == '*')
            c = comment();
        else
            ungetch(d);

    *w = '\0';
    return c;
}

/* comment: skip over comment and return a character */
int comment(void)
{
    int c, getch(void);
    void ungetch(int);

    while ( (c = getch()) != EOF)
        if ( c == '*')
            if ((c = getch()) == '/')
                break;
            else
                ungetch(c);
    
    return c;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possible pushed-back) character */
{
    return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}