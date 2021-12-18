
/* Exercise 5-5:
 * Write version of the library functions strncpy,strncat,and strncmp,which operate
 * on at most the first n characters of their argument atrings.For example,
 * strncpy(s,t,n) copies at most n characters of t to s.Full descriptions are in Appendix B.
 */

#include <stdio.h>

void mstrncpy(char *s, char *t,int n);
void mstrncat(char *s, char *t,int n);
int mstrend(char *s, char *t,int n);

int main(void)
{
    char s[20]="123.456";
    char t[20]="456";

    printf("%s\n",s);
    printf("%s\n",t);
    printf("-------------\n");
    mstrncat(s,t,2);
    printf("%s\n",s);
    printf("-------------\n");
    printf("%d\n",mstrend(s,t,2));
    mstrncpy(s,t,2);
    printf("-------------\n");
    printf("%s\n",s);
    printf("%s\n",t);

    return 0;
}

/* strcpy: copy t to s; pointer version 3 */
void mstrncpy(char *s, char *t,int n)
{
    while (n--)
        *s++ = *t++;
    *s = '\0';
}

void mstrncat(char *s, char *t,int n)
{
    while(*s)
        ++s;
    while(n--)
        *s++ = *t++;
}

int mstrend(char *s, char *t,int n)
{
    int i;

    while(*s)
    {
        for(i=0;*(s+i) == *(t+i) && i < n;i++)
            ;
        if(*(s+i-1) == *(t+i-1) && i == n)
        {
            *(s+i) = '\0';
            return 1;
        }
        ++s;
    }
    if(i < n)
        return 0;
}