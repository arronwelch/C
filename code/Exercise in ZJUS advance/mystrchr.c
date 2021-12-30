#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
    char s1[] = "hello";
    char *p = strchr(s1, 'l');
    printf("%s\n", p);
    p = strchr(p + 1, 'l');
    printf("%s\n", p);
    return 0;
}