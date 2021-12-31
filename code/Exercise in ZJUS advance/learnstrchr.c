#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*************************************************************************
 * char * strchr(const char *s, int c);  //find 'c' from left to right
 * char * strrchr(const char *s, int c); //find 'c' from right to left
 * NULL: no find
 * question 1: how to find 2nd 'c' in string [s].
 *************************************************************************/

int main(int argc, const char **argv)
{
    char s[] = "hello";
    char *p = strchr(s, 'l');
    printf("%s\n", p);
    p = strchr(p + 1, 'l');
    printf("%s\n", p);

    char *t = (char *)malloc(strlen(p)+1);
    strcpy(t,p);
    printf("%s\n", t);
    free(t);

    char c = *p;
    *p = '\0';
    char *t2 = (char *)malloc(strlen(s) + 1);
    strcpy(t2,s);
    printf("%s\n", t2);
    *p = c;//recover
    printf("%s\n",s);

    return 0;
}