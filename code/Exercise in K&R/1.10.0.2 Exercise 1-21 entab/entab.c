#include <stdio.h>

#define TABNUM 4

int main()
{
    char c;
    unsigned int spaceCount;

    spaceCount = 0;
    while ((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            ++spaceCount;
            if(spaceCount == TABNUM)
            {
                putchar('|');//replace '\t' for display tab
                spaceCount = 0;
            }
        }
        else if(spaceCount > 0)
        {            
            while (spaceCount)
            {
                putchar('.');//replace ' ' for display space
                --spaceCount;
            }
            putchar(c);
        }
        else
        {
            putchar(c);
        }
    }

    return 0;
}