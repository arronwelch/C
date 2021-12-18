
/* Exercise 5-4:
 * Write the function strend(s,t), which return 1 if the string t occurs at the end of the string s, and zero otherwise.
 */

#include <stdio.h>

int mstrend(char *s, char *t);

int main(void)
{
    char s[]="123.456";
    char t[]="456";
    mstrend(s,t);
    printf("%d",mstrend(s,t));

    return 0;
}

int mstrend(char *s, char *t)
{
    int n;

    while(*s)
    {
        for(n=0;*(s+n) == *(t+n) && *(t+n) != '\0';n++)
            ;
        if(*(s+n) == '\0' && *(t+n) == '\0')
            return 1;
        else if(*(s+n) == '\0')
            return 0;
        ++s;
    }
}