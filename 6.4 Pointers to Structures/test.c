
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
//int mbinsearch(char *, struct key *, int);
struct key *mbinsearch(char *, struct key *, int);

/* count C keywords; pointer version */
int main(void)
{
    //int n;
    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((p = mbinsearch(word, keytab, NKEYS)) != NULL)
                p->count++;

    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);

    return 0;
}

/* mbinsearch: find word in tab[0] ... tab[n-1] */
struct key *mbinsearch(char *word, struct key tab[], int n)
{
    int cond;

    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high)
    {
        mid = low + ( high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
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