#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getline(char line[], int maxline);
void reverse(char from[],char to[],int length);
/* print the longest input line */
int main()
{
    int len;               /* current line length */

    char line[MAXLINE];    /* current input line */
    char reline[MAXLINE];  /* reverse current input line */

    while ((len = getline(line, MAXLINE)) > 0)
    {        
        reverse(line,reline,len);
        printf("%s",reline);
    }

    return 0;
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

/* reverse: reverse 'from' into 'to'; assume to is big enough */
void reverse(char from[],char to[],int length)
{
    int i;

    i = 0;
    if(length > 1)
    {
        for(;i < length-1; i++)
            to[i] = from[length - 2 - i];        
    }
    to[i] = '\n';
    to[i+1] = '\0';
}