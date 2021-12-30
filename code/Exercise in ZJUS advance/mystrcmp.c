#include <stdio.h>
#include <string.h>

int mystrcmp(const char *s1, const char *s2)
{
    // int idx = 0;

    // while ( s1[idx] == s2[idx] && s1[idx] != '\0')
    // {
    //     // if(s1[idx] != s2[idx])
    //     // {
    //     //     break;
    //     // }
    //     // else if (s1[idx] == '\0')
    //     // {
    //     //     break;
    //     // }
    //     idx++;
    // }

    // return s1[idx] - s2[idx];

    while (*s1 == *s2 && *s1 != '\0')
    {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

int main(int argc, char **argv)
{
    char s1[] = "abc";
    char s2[] = "abc ";
    printf("%d\n", strcmp(s1, s2));
    printf("%d\n", mystrcmp(s1, s2));
    printf("%d\n", 'a' - 'A');
    printf("%d\n", '\0' - ' ');

    return 0;
}