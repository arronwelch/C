#include <stdio.h>  //printf
#include <string.h> //strcpy strlen
#include <stdlib.h> //malloc

/**
 * char * strcpy(char * restrict dst, const char * restrict src)
 eg.
 * char *dst = (char *)malloc(strlen(src)+1)
 * strcpy(dst,src)
 * dst --- destination
 * src --- source
 * */

char *mystrcmp(char *dst, const char *src)
{
    // int idx = 0;
    // while (src[idx] != '\0')
    // while (src[idx])
    // {
    //     dst[idx] = src[idx];
    //     idx++;
    // }
    // dst[idx] = '\0';

    // return dst;

    char *ret = dst;
    // while ( *src != '\0')
    // while (*src)
    // {
    //     *dst++ = *src++;
    //     // dst++;
    //     // src++;
    // }
    while (*dst++ = *src++)
        ;

    return ret;
}

int main(int argc, char **argv)
{
    char *src = "abcdef\nThis is next line";
    char *dst = (char *)malloc(strlen(src) + 1);
    char *mydst = (char *)malloc(strlen(src) + 1);

    strcpy(dst,src);
    printf("%s\n",dst);

    strcpy(mydst,src);
    printf("%s\n",mydst);


    free(dst);
    free(mydst);

    return 0;
}