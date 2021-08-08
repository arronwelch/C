#include <stdio.h>

/* 
 * Exercise 1-9. Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 */
int main()
{
    int c;

    while ( (c = getchar()) != EOF )
    {
        if(c == ' ')//blanks
        {
            putchar(c);
            while ( (c = getchar()) == ' ' )
                ;//a null statement
            putchar(c);
        }
        else
            putchar(c);        
    }

    return 0;
}