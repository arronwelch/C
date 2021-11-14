#include <stdio.h>

/* Exercise 1-12. 
 * Write a program that prints its input one word per line.
 */

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
            if(nw >= 2)
                putchar('\n');
            putchar(c);
        }
        else
            putchar(c);
    }
    printf("\n%d %d %d\n",nl,nw,nc);
    
    return 0;
}