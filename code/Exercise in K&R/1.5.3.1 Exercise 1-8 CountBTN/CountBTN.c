#include <stdio.h>

/* 
 * Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 * count blanks,tabs and newlines in input 
 */
int main()
{
    int c, blank, tab, newline;

    blank = 0;
    tab = 0;
    newline = 0;

    while ( (c = getchar()) != EOF )
    {
        if(c == ' ')//blanks
            ++blank;            
        else if(c == '\t')//tabs
            ++tab;            
        else if(c == '\n')//newlines
            ++newline;            
    }
    
    // printf("blanks count:%d\n",blank);
    // printf("tabs count:%d\n",tab);
    // printf("newlines count:%d\n",newline);
    printf("blank: %d\ntab: %d\nnewline: %d\n", blank, tab, newline);

    return 0;
}