
/* Exercise 7-4:(page 159 K&R)
 * Write a private version of scanf analogous to minprintf from the previous section.
 */

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT 100

void minscanf(char *fmt, ...);

int main(void)
{
    int day, year;
    char monthname[20];

    minscanf("%d %s %d", &day, monthname, &year); /* 25 Dec 1988 */
    printf("valid: %d %s %d", day, monthname, year);

    return 0;
}

/* minscanf: minimal scanf with variable argument list */
void minscanf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg */
    char *p, *sval;
    char localfmt[LOCALFMT];
    int c, i, *ival;
    unsigned *uval;
    double *dval;

    i = 0;             /* index for localfmt array */
    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            localfmt[i++] = *p; /* collect chars */
            continue;
        }
        localfmt[i++] = '%'; /* start format */
        while (*(p + 1) && !isalpha(*(p + 1)))
            localfmt[i++] = *++p; /* collect chars */
        localfmt[i++] = *(p + 1); /* format letter */
        localfmt[i] = '\0';
        switch (*++p) /* format letter */
        {
        case 'd':
        case 'i':
            ival = va_arg(ap, int *);
            scanf(localfmt, ival);
            break;
        case 'x':
        case 'X':
        case 'u':
        case 'o':
            uval = va_arg(ap, unsigned *);
            scanf(localfmt, uval);
            break;
        case 'f':
            dval = va_arg(ap, double *);
            scanf(localfmt, dval);
            break;
        case 's':
            sval = va_arg(ap, char *);
            scanf(localfmt, sval);
            break;
        default:
            scanf(localfmt);
            break;
        }
        i = 0; /* reset index */
    }
    va_end(ap); /* clear up */
}
