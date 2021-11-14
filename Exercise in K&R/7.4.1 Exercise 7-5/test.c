
/* Exercise 7-5:(page 159 K&R)
 * Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do 
 * the input and number conversion.
 */

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0' /* signal that a number was found */

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int c, i, rc;
    static char lastc[] = " ";

    sscanf(lastc,"%c", &c);
    lastc[0] = ' '; /* clear last character */
    while ((s[0] = c) == ' ' || c == '\t')
        if (scanf("%c",&c) == EOF)
            c = EOF;
    s[1]= '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        do
        {
            rc = scanf("%c",&c);
            if (!isdigit(s[++i] = c))
                break;
        } while (rc != EOF);
    if( c == '.') /* collect fraction part */
        do
        {
            rc = scanf("%c",&c);
            if (!isdigit(s[++i] = c))
                break;
        } while (rc != EOF);
    s[i] = '\0';
    if (rc != EOF)
        lastc[0] = c;
    return NUMBER;
}

