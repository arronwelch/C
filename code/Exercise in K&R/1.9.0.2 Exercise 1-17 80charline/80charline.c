#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define LIMIT 80 /*  print all input lines that are longer than 80 characters */
int getline(char line[], int maxline);

/* print the longest input line */
int main()
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */

    while ((len = getline(line, MAXLINE)) > 0)
        if (len > LIMIT)
        {
            printf("\n--->>>>\n");
            printf("lines that are longer than 80 characters:\n%s",line);
            printf("\n<<<<---\n");
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
