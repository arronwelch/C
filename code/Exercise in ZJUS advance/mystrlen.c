#include <stdio.h>
#include <string.h>

size_t mystrlen(const char *s)
{
    size_t idx = 0;
    while (s[idx] != '\0')
    {
        idx++;
    }
    return idx;
}

int main(int argc, char **argv)
{
    char line[] = "Hello";
    printf("strlen = %lu\n",mystrlen(line));
    printf("sizeof = %lu\n",sizeof(line));

    return 0;
}