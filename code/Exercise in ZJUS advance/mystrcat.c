#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *mystrcat(char *dest, const char *src);

char *mystrcat(char *dest, const char *src)
{
    char *ret = dest;
    while (*dest != '\0')
    {
        dest++;
    }
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return ret;
}

int main(int argc, char *argv[])
{
    char s1[7] = "abc";
    char s2[] = "d_f";
    char *p = mystrcat(s1, s2);
    char *t = (char *)malloc(strlen(s1) + 1);
    strcpy(t, p);
    printf("%s\n",t);
    free(t);

    return 0;
}