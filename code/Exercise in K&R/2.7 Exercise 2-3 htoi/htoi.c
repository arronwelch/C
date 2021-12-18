
/*
 * Exercise 2-3. 
 * Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
 * through 9, a through f, and A through F.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
int getline(char line[], int maxline);
int htoi(char s[]);

int main()
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */

    while ((len = getline(line, MAXLINE)) > 0)
    {
        printf("hex2dec:%d\n",htoi(line));
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

/* htoi: convert s to integer */
int htoi(char s[])
{
    int i, n;

    i = 0;
    n = 0;
    while(s[i] != '\n')
    {
        if(s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) 
            i=i+2;
        
        if(s[i] >= '0' && s[i] <= '9')
            n = 16 * n + (s[i] - '0');
        else if(s[i] >= 'a' && s[i] <= 'f')
            n = 16 * n + (s[i] - 'a' + 10);
        else if(s[i] >= 'A' && s[i] <= 'F')
            n = 16 * n + (s[i] - 'A' + 10);
        else
            return -1;
        
        i++;
    }
        
    return n;
}