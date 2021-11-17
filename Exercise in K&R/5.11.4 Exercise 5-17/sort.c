/**
 * Exercise 5-17:(page 121 K&R)
 * Add a field-handing capability, so sorting may be done in fields within lines.
 * each field sorted according to an independent set of options.
 * (The index for this book was -df for the index category and -n for the page numbers.)
 * 
 * gcc -o main.exe alloc.c arg.c cmp.c error.c lines.c main.c sort.c substr.c
 * Usage: ./main -dfnr [+pos1] [-pos2]
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMERIC 1    /* numeric sort */
#define DECR 2       /* sort in decreasing order */
#define FOLD 4       /* fold upper and lower cases */
#define DIR 8        /* directory order */

#define MAXLINES 100 /* max of lines to be sorted */
#define MAXLEN 100   /* max length of any input lines */
#define MAXSTR 100

void readargs(int argc, char *argv[]);
int mgetline(char *str, int lim);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int decr);
void substr(char *s, char *t, int maxstr);
int numcmp(char *s1, char *s2);
int charcmp(char *s, char *t);
void error(char *s);
void mqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

char option = 0;
int pos1 = 0; /* field beginning with pos1 */
int pos2 = 0; /* ending just before pos2 */

int main(int argc, char *argv[])
{
    char *lineptr[MAXLINES]; /* pointer to text lines */
    int nlines;              /* number of input lines read */
    int rc = 0;

    readargs(argc, argv);
    if ((nlines = readlines(lineptr, MAXLINES)) > 0)
    {
        if (option & NUMERIC)
        {
            mqsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp);
        }
        else
        {
            mqsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))charcmp);
        }
        writelines(lineptr, nlines, option & DECR);
    }
    else
    {
        printf("input too big to sort \n");
        rc = -1;
    }
    return rc;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    char str[MAXSTR];

    substr(s1, str, MAXSTR);
    v1 = atof(str);
    substr(s2, str, MAXSTR);
    v2 = atof(str);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* charcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int charcmp(char *s, char *t)
{
    char a, b;
    int i, j, endpos;

    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & DIR) ? 1 : 0;

    i = j = pos1;
    if (pos2 > 0)
    {
        endpos = pos2;
    }
    else if ((endpos = strlen(s)) > strlen(t))
    {
        endpos = strlen(t);
    }
    do
    {
        if (dir)
        {
            while (i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0')
                i++;
            while (j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
                j++;
        }
        if (i < endpos && j < endpos)
        {
            a = fold ? tolower(s[i]) : s[i];
            i++;
            b = fold ? tolower(t[j]) : t[j];
            j++;
            if (a == b && a == '\0')
                return 0;
        }
    } while (a == b && i < endpos && j < endpos);
    return a - b;
}

void mqsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;    

    void swap(void *v[], int i, int j);/* declare swap function */

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    mqsort(v, left, last - 1, comp);
    mqsort(v, last + 1, right, comp);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* readargs: read program arguments */
void readargs(int argc, char *argv[])
{
    int c;

    while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+')/* get second lines's first character */
    {
        if (c == '-' && !isdigit(*(argv[0] + 1)))/* not is digit */
        {
            while (c = *++argv[0])/* get second lines's second character and go on until '\0',first character is '-' */
            {
                switch (c)
                {
                case 'd': /* directory order */
                    option |= DIR;
                    break;
                case 'f': /* fold upper and lower */
                    option |= FOLD;
                    break;
                case 'n': /* numeric sort(directory and fold is not work at same time) */
                    option |= NUMERIC;
                    break;
                case 'r': /* sort in decreasing order */
                    option |= DECR;
                    break;
                default:
                    printf("sort: illegal option %c \n", c);
                    error("Usage: sort -dfnr [+pos1] [-pos2]");
                    break;
                }
            }
        }
        else if (c == '-' ) /* isdigit */
            pos2 = atoi(argv[0] + 1);/* get pos2(end position) */
        else if ((pos1 = atoi(argv[0] + 1)) < 0 ) /* not is digit returns zero,first character is '+' */
            error("Usage: sort -dfnr [+pos1] [-pos2]");
    }
    if (argc || pos1 > pos2)
        error("Usage: sort -dfnr [+pos1] [-pos2]");
}


#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) /* it fits */
    {
        allocp += n;
        return allocp - n; /* return old position */
    }
    else
        return 0; /* not enough room */
}

/* error: print error message and exit */
void error(char *s)
{
    printf("%s\n", s);
    exit(1);
}

/* mgetline: version in pointers read a line into str, return length */
int mgetline(char *str, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *(str + i) = c;
    if (c == '\n')
    {
        *(str + i) = c;
        ++i;
    }
    *(str + i) = '\0';
    return i;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mgetline(line, MAXLEN)) > 1)/* newline's lines end */
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;/* too many input */
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int decr)
{
    int i;

    if (decr)
        for (i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
}

/* substr: get a substring of s and put in str */
void substr(char *s, char *str, int maxstr)
{
    int i, j, len;
    
    len = strlen(s);
    if (pos2 > 0 && len > pos2)
        len = pos2;
    else if (pos2 > 0 && len < pos2)
        error("subetr: string too short");
    if (len > maxstr)
        len = maxstr;
    for (j = 0, i = pos1; i < len; i++, j++)
        str[j] = s[i];
    str[j] = '\0';
}
