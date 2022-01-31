#include <stdio.h>

int getLastStrLen(void) 
{
    int c,len = 0;
    while((c = getchar()) != '\n')
    {
        len++;
        if(c == ' ')
            len = 0;
    }
    return len;
}

int main()
{
    printf("%d\n",getLastStrLen());
    return 0;
}