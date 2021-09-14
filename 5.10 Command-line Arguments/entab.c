/**
 * Exercise 5-11:
 * Modify the program entab and detab (written as exercise in Chapter 1) to 
 * accept a list of tab stops as arguments.Use the default tab settings
 * if there are no arguments.
 */

#include <stdio.h>
#include <stdlib.h> /* for atoi() */
#include <string.h> /* for strlen() */

#define MAXLEN 1000 /* max length of input/output line   */
#define MAXTABS 100 /* max number of tab stop position   */
#define N 4         /* default tabstops (every n column) */

/* function declaration */
int getLine(char *,int );
int setTabList(int , char **, int *);
int tabStopPos(int , int *, int );
void entab(char *, char *, int *, int );

int main(int argc, char *argv[])
{
    char in[MAXLEN]; /* currently read line */
    char out[MAXLEN];/* modified line */
    int tabList[MAXTABS]; /* a list of tab stop positions */
    int tlSize;/* size of tablist */

    if ( (tlSize = setTabList(argc,argv,tabList) ) < 0)
        return 1;
    while (getLine(in,MAXLEN) > 0)
    {
        entab(in,out,tabList,tlSize);
        printf("%s",out);
    }

    return 0;
}

int getLine(char *s,int lim)
{
    int c;
    char *len;

    len = s;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n');
        *s++ = c;
    *s = '\0';
    return strlen(len);
}

/* setTabList:extracts topstops positions from command line arguments and
 * store them in tabList.Return size of tabList,0 if no tabstop list was
 * provided, or -1 if arg is an invalid tabstop value.
 */
int setTabList(int count, char **arg, int *tabList)
{
    int i;

    for ( i=0; --count > 0;++i)
        if (!(tabList[i] = atoi(*++arg)) || tabList[i] < 0)
        {
            printf("Invalid tabstop: %s\n",*arg);
            return -1;
        }
    return i;/* i is 0 if no tablist */
}

/* tabStopPos:return the next tab stop positions from tabList, 
 * or if not tablist,return default tab stop.
 */
int tabStopPos(int column, int *tabList, int tlSize)
{
    if (!tlSize)
        return N;
    
    /* if list exits, find the next tab stop position in it */
    while (column >= *tabList)
    {
        ++tabList;
        --tlSize;
    }
    return *tabList - tlSize;
}


/* entab function:replace blanks with the minimum number of the tabs and blanks
 */
void entab(char *in, char *out, int *tabList, int tlSize)
{
    int i;/* index for read line */
    int j;/* index for modified(written) line */
    int nblanks;/* number of required blanks */
    int ntabs;/* number of required tabs */
    int tabStop; /* next tabstop position */

    for (i=j=0; in[i] != '\0';++i)
    {
        if (in[i] == ' ')
        {
            for (nblanks = ntabs = 0; in[i] == ' ';++i) /* count blanks */
            {
                tabStop = tabStopPos(i, tabList, tlSize);
                if ( (i+1) % tabStop == 0) /* replace every N blanks with a tab */
                {
                    ++ntabs;
                    nblanks = 0;/* reset */
                }
                else
                    ++nblanks;
            }
            --i;/* adjust position after the loop */
            while (ntabs-- > 0)/* insert tabs */
                out[j++] = '\t';
            while (nblanks-- > 0)/* insert remaining blanks */
                out[j++] = ' ';
        }
        else
            out[j++] = in[i]; /* copy all other characters */
    }
    out[j] = '\0';
}

