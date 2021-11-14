
#include <stdio.h>
#include <ctype.h>

int main(void) /* lower: convert input to lower case */
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(tolower(c));

    return 0;
}

/* 

 int getchar(void);

 EOF -1

 if a program [prog] uses (getchar), then the command line：

 prog < infile

 causes [prog] to read characters from [infile] instead.

 on some systems, the command line:

 otherprog | prog

 runs the two programs [otherprog] and [prog], and pipes the standard output of [otherprog] into the standard input of [prog]
 */