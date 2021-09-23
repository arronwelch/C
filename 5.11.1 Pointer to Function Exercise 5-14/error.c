/**
 * Exercise 5-14:(page 121 K&R)
 * Modify the sort program to handle a -r flag, wihich indicates sorting in reverse(decreasing) order. Be sure that -r works with -n.
 * 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMERIC 1    /* 0x0000 0001 numeric sort */
#define DECR 2       /* 0x0000 0010 sort in decreasing order */
#define MAXLINES 100 /* max of lines to be sorted */
#define MAXLEN 1000 /* max length of any input lines */
char *lineptr[MAXLINES]; /* pointers to text lines */

int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void mqsort(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int decr);
int getline(char *,int);
char *alloc(int);
static char option = 0;

/* sort input lines */
int main(int argc, char *argv[])
{

    int nlines;              /* number of input lines read */
    int c, rc = 0;

    while (--argc > 0 && ((*++argv)[0] == '-'))
    {
        while (c = *++argv[0])
        {
            switch (c)
            {
            case 'n': /* numeric sort */
                option |= NUMERIC;
                break;
            case 'r': /* sort in decreasing order */
                option |= DECR;
                break;
            default:
                printf("sort: illegal option %c\n",c);
                argc = 1;
                rc = -1;
                break;
            }
        }
    }

    if (argc)
        printf("Usahe: sort -nr \n");
    else
        if ( (nlines = readlines(lineptr,MAXLINES)) > 0)
        {
            if(option & NUMERIC)
                mqsort( (void **) lineptr, 0, nlines-1,(int (*) (void *,void *)) numcmp );
            else
                ;//mqsort( (void **) lineptr, 0, nlines-1,(int (*) (void *,void *)) strcmp );
            writelines(lineptr,nlines,option&DECR);
        } 
        else
        {
            printf("input too big to sort \n");
            rc = -1;
        }
    return rc;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int decr)
{
    int i;

    if (decr)  /* print in decreasing order */
        for (i = nlines -1; i >= 0; i--)
            printf("%s\n",lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s\n",lineptr[i]);
}

void mqsort(void *v[], int left, int right, int (*comp) (void *, void *))
{
    int i, last;

    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */

    swap(v, left, (left+right)/2);
    last = left;
    for (i = left + 1;i <= right; i++)
        if ((*comp)(v[i],v[left]) < 0)
            swap(v,++last,i);
    swap(v,left,last);
    mqsort(v,left,last-1,comp);
    mqsort(v,last+1,right,comp);
}
/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else
        return 0;
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[],int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while( (len = getline(line,MAXLEN)) > 1 )
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0';/* delete newline */
            strcpy(p,line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
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
        return 0;/* not enough room */
}