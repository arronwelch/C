#include <stdio.h>

#define COLUMN 8
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
int deleteTrailingSpace(char s[],int length);

int main()
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */

    while ((len = getline(line, COLUMN)) > 0)
    {
        deleteTrailingSpace(line,len);
        printf("%s\n",line);
    }

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
/* delete trailing blanks, tabs and entirely blank lines */
int deleteTrailingSpace(char s[],int length)
{
    int i;
    if(length > 1)
    {
        for ( i = length-1; s[i] == ' ' || s[i] == '\t'; i--);

        //s[i+1] = '\n';
        s[i+1] = '\0';
        //s[i+2] = '\0';
    }

    return i+1;
}