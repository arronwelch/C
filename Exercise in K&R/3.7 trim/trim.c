
#include<stdio.h>
#include<string.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char s[], int lim);
int trim(char s[]);

int main(void)
{
	char str[MAXLINE];

    getline(str,MAXLINE);

	printf("%s",str);
    putchar('|');

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

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
    int n;
    for (n = strlen(s)-1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
        break;
    s[n+1] = '\0';
    return n;
}