
// Open in integrated Terminal
// .\mecho "hello," world

//argv is a pointer to the beginning of the array of argument strings
//argv[0] is "m2echo"
//argv[1] is "hello,"
//argv[2] is "world"

#include <stdio.h>

/* echo command-line arguments: 2nd version */
int main(int argc, char *argv[])
{
    while(--argc > 0)
        // printf("%s%s", *++argv, (argc > 1) ? " " : "");
        printf((argc > 1) ? "%s " : "%s",*++argv);//this shows that the format argument of printf can be an expression too.
    printf("\n");
    return 0;
}