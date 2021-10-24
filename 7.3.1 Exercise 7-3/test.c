
/*
 * Exercise 7-3:(page 156 K&R)
 * Revise minprintf to handle more of the other facilities of printf.
 */

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT 100

void minprintf(char *fmt, ...);

int main(void)
{
    minprintf("test:%d,%i,%x,%X,%u,%o,%f,%s\n",1,2,0x03,0x04,5,06,7.0,"String");

    return 0;
}

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
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