
#include <stdio.h>

#define MAXLINE 100

int getline(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    int day, month, year;
    char monthname[20];

    while (getline(line, sizeof(line)) > 0)
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n", line); /* 25 Dec 1988 form */
        else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("valid: %s\n", line); /* mm/dd/yy form */
        else
            printf("invalid: %s\n", line); /* invalid form */
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

/*
    A final warning: the argument to scanf and sscanf must be pointers.
    This error is not generally detected at compile time.
*/