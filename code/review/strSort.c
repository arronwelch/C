#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 1000
#define MAX_LEN  1000
#define MAX_CNT  1000

short int getStr(char *argv[])
{
    char x,str[MAX_LEN];
    short int len = 0;
    short int line = 0;
    while(scanf("%c",&x) != EOF)
    {
        str[len++] = x;
        str[len] = '\0';
        if(x == '\n')
        {
            argv[line] = (char *)malloc(sizeof(char)*(len+1));
            strcpy(argv[line++],str);
            len = 0;
        }
    }
    return line;
}

void swap(char *argv[],short int i, short int j)
{
    char *tmp;
    tmp = argv[i];
    argv[i] = argv[j];
    argv[j] = tmp;
}

void bubbleSortStr(short int argc,char *argv[])
{
    for (short int i = 0; i < argc-1; i++)
    {
        for (short int j = i+1; j < argc; j++)
        {
            if( strcmp(argv[i],argv[j]) > 0)
                swap(argv,i,j);
        }
    }
}

int main()
{
    char *argv[MAX_WORD];
    short int argc;
    short int n;
    scanf("%hd\n",&n);
    argc = getStr(argv);
    bubbleSortStr(argc,argv);
    for(short int i = 0; i < argc; i++)
        printf("%s",argv[i]);
    return 0;
}