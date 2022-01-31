/*
  0     1      2
['a'] ['\n'] ['\0']
*/

#include <stdio.h>

#define MAX_LEN 1000

int getStr(char str[])
{
    int len = 0;
    while((str[len++] = getchar()) != '\n');
    str[len] = '\0';
    return len;
}

int main()
{
    char str[MAX_LEN] = {0};
    int len = getStr(str);
    for(int i = len - 2; i >= 0; i--)
        putchar(str[i]);
    return 0;
}