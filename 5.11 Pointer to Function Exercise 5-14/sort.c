/**
 * Exercise 5-14: (page 120 K&R)
 * Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order.
 * Be sure that -r works with -n.
*/

#include <stdio.h>
#include <string.h>

#define NUMERIC 1 /* numeric sort */
#define DECR 2 /* sort in decreasing order */
#define LINES 100 /* max of lines to be sorted */
#define MAXLEN 1000 /* max length of any input lines */

int getline(char *,int);
char *alloc(int);
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void qsort(char *v[], int left, int right, int (*comp)(void *, void *) );
void writelines(char *lineptr[], int nlines, int decr);

static char option = 0;

/* sort input lines */
int main(int argc, char *argv[])
{
    char *lineptr[LINES];/* pointer to text lines */
    int nlines;/* number of input lines read */
    int c, rc = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c == *++argv[0])
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
    
    if (argc)
        printf("Usage: sort -nr \n");
    else
        if ( (nlines = readlines(lineptr,LINES) ) > 0)
        {
            if (option & NUMERIC)
                qsort( (void **) lineptr, 0, nlines-1,(int (*) (void *,void *)) numcmp );
            else
                qsort( (void **) lineptr, 0, nlines-1,(int (*) (void *,void *)) strcmp );
            writelines(lineptr, nlines, option & DECR);
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

    if (decr) /* print in decreasing order */
        for ( i = nlines-1;i >= 0;i--)
            printf("%s\n",lineptr[i]);
    else
        for (i = 0;i < nlines; i++)
            printf("%s\n",lineptr[i]);
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

/* qsort: sort v[left] ...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */ //the repeat process end condition
    
    swap(v,left,(left+right)/2);//random from the array middle element
    last = left;//suposible it is the last element

    for (i = left + 1; i <= right; ++i)//find the element less than left
        if (strcmp(v[i],v[left]) < 0)
            swap(v,++last,i);//move fewer than v[left] element to the next position from last,last+1,...,to the recently last
    swap(v,left,last);//interchange the recently last with the left
    qsort(v,left,last-1);//so,the left part element is less than last
    qsort(v,last+1,right);//the right part element is more than last,repeat this process
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[],int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}