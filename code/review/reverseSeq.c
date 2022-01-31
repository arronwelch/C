#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 1000
#define MAX_LEN  1000

short int getStr(char *argv[])
{
    char x,str[MAX_LEN];
    short int len = 0;
    short int line = 0;
    while(scanf("%c",&x) != EOF)
    {
        str[len++] = x;
        if(x == '\n')
            str[len-1] = ' ';
        str[len] = '\0';
        if(x == ' ' || x == '\n')
        {
            argv[line] = (char *)malloc(sizeof(char)*(len+1));
            strcpy(argv[line++],str);
            len = 0;
        }
    }
    return line;
}

void printStr(char str[])
{
    short int i = 0;
    while(str[i] != '\0')
    {
        putchar(str[i++]);
    }
}

int main()
{
    char *argv[MAX_WORD];
    short int line = getStr(argv);
    for(short int i = line-1; i >= 0; i--)
    {
        printStr(argv[i]);
        free(argv[i]);
    }
    printf("\n");

    return 0;
}