
#include <stdio.h>

int main(int argc, const char *argv[])
{
    for (size_t i = 0; i < argc; i++)
    {
        printf("%d:%s\n", i, argv[i]);
    }

    return 0;
}