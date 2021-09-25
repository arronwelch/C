/**
 * Exercise 5-17:(page 121 K&R)
 * Add a field-handing capability, so sorting may be done in fields within lines.
 * each field sorted according to an independent set of options.
 * (The index for this book was -df for the index category and -n for the page numbers.)
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define NUMERIC 1 /* numeric sort */
#define DECR 2 /* sort in decreasing order */
#define FOLD 4 /* fold upper and lower cases */
#define DIR 8 /* directory order */
#define MAXLINES 100 /* max of lines to be sorted */
#define MAXLEN 100 /* max length of any input lines */

int charcmp(char *, char *);
void error(char *);
int numcmp(char *,char *);
void readargs(int argc, char *argv[]);
int readlines(char *lineptr[],int maxlines);
void mqsort(void *lineptr[], int left, int right, int (*comp)(void *,void *) );
void writelines(char *lineptr[],int nlines,int decr);

char option = 0;
int pos1 = 0;/* field beginning with pos1 */
int pos2 = 0;/* ending just before pos2 */

/* sort input lines */
int main(int argc, char *argv[])
{
    char *lineptr[MAXLINES];/* pointer to text lines */
    int nlines; /* number of input lines read */
    int rc = 0;

    readargs(argc,argv);
    if ((nlines = readlines(lineptr,MAXLINES)) >0 )
    {
        if (option & NUMERIC)
        {
            mqsort((void **) lineptr,0,nlines - 1,(int (*)(void *,void *)) numcmp );
        }
        else
        {
            mqsort((void **) lineptr,0,nlines - 1,(int (*)(void *,void *)) charcmp );
        }
        writelines(lineptr,nlines,option & DECR);
    }
    else
    {
        printf("input too big to sort \n");
        rc = -1;
    }
    return rc;
}

/* readargs: read program arguments */
void readargs(int argc, char *argv[])
{
    int c;
    int atoi(char *);

    while ( --argc > 0 && (c = (*++argv[0]) == '-' || c == '+') )
    {
        if (c == '-' && !isdigit(*(argv[0]+1)))
        {
            
        }
        
    }
    
}



