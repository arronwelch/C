/* 
 * Exercise 5-11. Modify the program and detab (written in exercises in Chapter
 * 1) to accept a list of tab stops as arguments. Use the default tab setting
 * if there are no arguments.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000 /* max length of input/output line */
#define MAXTABS 100 /* max number of tab stop positions */
#define N 4 /* default tabstops (every n columns) */

/* functions */
int getLine(char *,int);
int setTabList(int,char **,int *);
int ToTabStop(int, int *, int);
void detab(char *, char *, int *, int);

/* getLine function: read a line into s, return length */
int getLine(char *s, int lim)
{
    int c;
    char *len;

    len = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return strlen(len); 
}

int setTabList(int argc, char **arg, int *tabList)
{
    int i;

    for (i = 0; --argc > 0; ++i)
        if (!(tabList[i] = atoi(*++arg)) || tabList[i] < 0)//is positive number
        {
            printf("Invalid tabstop: %s\n", *arg);
            return -1;
        }
    return i;//argc
}

int ToTabStop(int column, int *tabList, int tlSize)
{
    if (!tlSize)//use default setting tab stop
        return N - (column % N);
    /* if tabList exits, find nearest tab stop position in it */
    while (tlSize != 0 && column >= *tabList)
    {
        ++tabList;//??
        --tlSize;
    }
    return *tabList - column;
}

void detab(char *in, char *out, int *tabList, int tlSize)
{
    int i;/* index for read line */
    int j;/* index for modified(written) line */
    int nblanks; /* number of required blanks */

    for (i = j = 0; in[i] != '\0'; i++)
    {
        if (in[i] == '\t')
        {
            nblanks = ToTabStop(j, tabList, tlSize);
            while (nblanks-- > 0)
                out[j++] = ' ';
        }
        else
            out[j++] = in[i];
    }

        out[j] = '\0';
}

int main(int argc, char *argv[])
{
    char in[MAXLEN];        /* currently read line */
    char out[MAXLEN];       /* modified line */
    int tabList[MAXTABS];   /* a list of tab stop positions */
    int tlSize;             /* size of tablist */

    if ((tlSize = setTabList(argc, argv, tabList)) >= 0)
        while (getLine(in, MAXLEN) > 0)
        {
            detab(in, out, tabList,tlSize);
            printf("%s",out);
        }
    return 0;
}