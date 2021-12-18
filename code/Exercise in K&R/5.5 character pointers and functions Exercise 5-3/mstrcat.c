
/* Exercise 5-3:
 * Write a pointer version of the function strcat that we showed in chapter 2:
 * strcat(s,t) copies the string t to the end of s.
 */

#include <stdio.h>

void mstrcat(char *s, char *t);

int main(void)
{
    char s[]="123";
    char t[]=".456";
    mstrcat(s,t);
    printf("%s",s);

    return 0;
}

void mstrcat(char *s, char *t)
{
    while(*s)
        ++s;
    while(*s++ = *t++);
}