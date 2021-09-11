
/**
 * test input line:
 * defghi
 * jklmnopqrst
 * abc
 */


#include <stdio.h> // a hash sign (#)
#include <string.h>

#define MAXLINES 5000 /* max lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */ //this is a pointer arays

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main(void)
{
    int nlines; /* number of input lines read */

    if ( (nlines = readlines(lineptr,MAXLINES)) >= 0)
    {
        qsort(lineptr,0,nlines - 1);
        writelines(lineptr,nlines);
        putchar((int)(**lineptr));//*lineptr[i] is the character it points to, \
                                       the first character of the i-th saved text line.
        putchar((int)(*lineptr[1]));//the first character of the 2nd text line.
        putchar((int)(**(lineptr+1)));
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input lines */
int getline(char *,int);
char *alloc(int);

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

// /* writelines: write output lines */
// void writelines(char *lineptr[],int nlines)
// {
//     int i;

//     for (i = 0; i < nlines; i++)
//         printf("%s\n",lineptr[i]);
// }

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

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while ( nlines-- )
        printf("%s\n", *lineptr++ );
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