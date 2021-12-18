
/* Exercise 4-12:
 * Adapt the ideas of printd to write a recursive version of itoa;
 * that is,convert an integer into a string by calling a recursive rountine.
 */

#include <stdio.h>

void printd(int n);
int main(void)
{
    int n = 12345;
    printd(n);

    return 0;
}

/* printd: print n in decimal */
void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    
    putchar(n % 10 + '0');
}
