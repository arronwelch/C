
/**
 * Exercise 8-1:(page 174 K&R)
 * Rewrite the program cat from Chapter 7 using read, write, open, and close instead of their standard library equivalents.
 * Perform experiments to determine the relative speeds of the two versions.
 */

#include <stdio.h>
#include <fcntl.h>
// #include "syscalls.h" //???
#include <stdlib.h>

void error(char *fmt, ...);
void merror(char *fmt, ...);

/* cat: concatenate files - read/write/open/close */
int main(int argc, char *argv[])
{
    int fd;
    void filecopy(int ifd, int ofd);

    if (argc == 1)      /* no args: copy standard input */
        filecopy(0, 1); //descriptors 0, 1, and 2, called the standard input, the standard output, and the standard error.
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY)) == -1)
                error("cat: can't open %s", *argv);
            else
            {
                filecopy(fd, 1);
                close(fd);
            }

    return 0;
}

/* filecopy: copy file ifd to ofd */
void filecopy(int ifd, int ofd)
{
    int n;
    char buf[BUFSIZ];

    while ((n = read(ifd, buf, BUFSIZ)) > 0)
        if (write(ofd, buf, n) != n)
            error("cat: write error");
}

// #include <stdarg.h>
// #include <ctype.h>
// #define LOCALFMT 100

// void error(char *fmt, ...)
// {
//     va_list ap; /* points to each unnamed arg */
//     char *p, *sval;
//     char localfmt[LOCALFMT];
//     int i, ival;
//     unsigned uval;
//     double dval;

//     va_start(ap, fmt); /* make ap point to 1st unnamed arg */
//     for (p = fmt; *p; p++)
//     {
//         if (*p != '%')
//         {
//             putchar(*p);
//             continue;
//         }
//         i = 0;
//         localfmt[i++] = '%'; /* start local fmt */
//         while (*(p + 1) && !isalpha(*(p + 1)))
//             localfmt[i++] = *(p + 1); /* collect chars */
//         localfmt[i++] = *(p + 1);     /* format letter */
//         localfmt[i] = '\0';
//         switch (*++p) /* format letter */
//         {
//         case 'd':
//         case 'i':
//             ival = va_arg(ap, int);
//             printf(localfmt, ival);
//             break;
//         case 'x':
//         case 'X':
//         case 'u':
//         case 'o':
//             uval = va_arg(ap, unsigned);
//             printf(localfmt, uval);
//             break;
//         case 'f':
//             dval = va_arg(ap, double);
//             printf(localfmt, dval);
//             break;
//         case 's':
//             sval = va_arg(ap, char *);
//             printf(localfmt, sval);
//             break;
//         default:
//             printf(localfmt);
//             break;
//         }
//     }
//     va_end(ap); /* clean up */
// }

#include <stdio.h>
#include <stdarg.h>
/* error: print an error message and die */
void error(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    //vprintf(stderr, fmt, args);
    vprintf(fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}