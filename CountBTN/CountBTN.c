#include <stdio.h>

/* 
 * Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 * count blanks,tabs and newlines in input 
 */
int main()
{
    int c, bl, tl, nl;

    bl = 0;
    tl = 0;
    nl = 0;

    while ( (c = getchar()) != EOF )
    {
        if(c == ' ')//blanks
            ++bl;
        else if(c == '\t')//tabs
            ++tl;
        else if(c == '\n')//newlines
            ++nl;
    }
    
    printf("blanks count:%d\n",bl);
    printf("tabs count:%d\n",tl);
    printf("newlines count:%d\n",nl);

    return 0;
}
