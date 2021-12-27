#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
    printf("EOF\n");//use ctrl+D,tell shell "EOF"

    return 0;
}