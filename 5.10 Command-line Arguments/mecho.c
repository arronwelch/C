
// Open in integrated Terminal
// .\mecho "hello," world

//argv is a pointer to an array of pointers
//argv[0] is the name by which the program was invoked,so argc is at least 1. "mecho"
//argv[1] is "hello,"
//argv[2] is "world"
//additionally,the standard requires that argv[argc] be a NULL pointer.

#include <stdio.h>

/* echo command-line arguments: 1st version */
int main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc -1) ? " " : "");
    printf("\n");
    return 0;
}