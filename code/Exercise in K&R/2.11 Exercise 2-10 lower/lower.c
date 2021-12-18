
/* 
 * Exercise 2-10. 
 * Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else.
 */

#include <stdio.h>

char lower(char uc);

int main(void)
{
    printf("please input upper char:");
    printf("tranform lower char = %c \n",lower(getchar()));

    return 0;
}

/* getbits: get n bits from position p */
char lower(char uc)
{
    return ( (uc >= 'A' && uc <= 'Z') ? (uc - 'A' + 'a') : uc );
}