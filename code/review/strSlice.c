#include <stdio.h>

#define LEN_MAX 1000

int mgetline(char line[],int max_length)
{
    int len = 0;
    int c = 0;
    while(--max_length > 0 && (c=getchar()) != '\n' && c != EOF)
    {
        line[len++] = c;
    }
    if(c== '\n')
        line[len++] = '\n';
    line[len] = '\0';
    
    if(c==EOF)
        len = EOF;

    return len;
}

void printline(char line[])
{
    int index = 0;
    int last = 0;
    while(line[index] != '\n')
    {
        if(index%8 == 0 && index != 0)
        {
            last = 0;
            putchar('\n');
        }
        putchar(line[index]);
        index++;
        last++;
    }

    if(line[index] == '\n')
    {
        while(last<8)
        {
            putchar('0');
            last++;
        }
    }
    putchar('\n');
}

int main()
{
    int len = 0;
    char line[LEN_MAX];
    while( (len = mgetline(line,LEN_MAX)) > 0 && len != EOF)
    {
        printline(line);
    }

    return 0;
}