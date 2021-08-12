#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
#define SPACE 4

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void detab(char s[],int length);
void append(char head[],char end[]);

int main(void)
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */

    while ((len = getline(line, MAXLINE)) > 0)
    {
        detab(line,len);
        printf("%s",line);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* detab that replaces tabs  */
void detab(char s[],int length)
{
    int i;
    char ls[MAXLINE];

    i = 0;
    for(i = 0;i < length;i++)
    {
        if(s[i] == '\t')
        {
            copy(ls,s+i+1);
            append(s,"....");
            append(s,ls);
        }
    }
}

void append(char head[],char end[])
{
    int i,j;

    for(i =0;i < MAXLINE;i++)
    {
        if(head[i] == '\0')
        {
            for(j = 0;j < MAXLINE && end[j] != '\0';j++,i++)
            {
                head[i] = end[j];
            }
            break;
        }
    }
}