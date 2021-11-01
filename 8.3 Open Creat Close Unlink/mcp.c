#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
// #include "syscalls.h"
#define PERMS 0666 /* RW for owner, group , others */

void error(char *, ...);

/* cp: copy f1 to f2 */
int main(int argc, char *argv[])
{
    int f1, f2, n;
    char buf[BUFSIZ];

    if (argc != 3)
        error("Usage: cp from to");
    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
        error("cp: can't open %s", argv[1]);
    if ((f2 = creat(argv[2], PERMS)) == -1)
        error("cp: can't create %s, mode %03o", argv[2], PERMS);

    while ((n = read(f1, buf, BUFSIZ)) > 0)
        if (write(f2, buf, n) != n)
            error("cp: write error on file %s", argv[2]);
    
    unlink(argv[1]);
    remove(argv[2]);

    return 0;
}

#include <stdarg.h>
#include <ctype.h>
#define LOCALFMT 100

void error(char *fmt, ...)
{
    va_list ap;/* points to each unnamed arg */
    char *p, *sval;
    char localfmt[LOCALFMT];
    int i, ival;
    unsigned uval;
    double dval;

    va_start(ap,fmt);/* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }
        i = 0;
        localfmt[i++] = '%'; /* start local fmt */
        while (*(p+1) && !isalpha(*(p+1)))
            localfmt[i++] = *(p+1); /* collect chars */
        localfmt[i++] = *(p+1);/* format letter */
        localfmt[i] = '\0';
        switch (*++p) /* format letter */
        {
        case 'd':
        case 'i':
            ival = va_arg(ap,int);
            printf(localfmt,ival);
            break;
        case 'x':
        case 'X':
        case 'u':
        case 'o':
            uval = va_arg(ap,unsigned);
            printf(localfmt,uval);
            break;
        case 'f':
            dval = va_arg(ap,double);
            printf(localfmt,dval);
            break;
        case 's':
            sval = va_arg(ap, char *);
            printf(localfmt,sval);
            break;
        default:
            printf(localfmt);
            break;
        }
    }
    va_end(ap);/* clean up */
}
