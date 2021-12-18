
/* 
 * Exercise 2-6. 
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
 * position p set to the rightmost n bits of y, leaving the other bits unchanged.
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n,unsigned y);

int main(void)
{
    printf("\nsetbits = 0x%2x\n",setbits(0x6b,4,3,0xd4));

    return 0;
}

/* setbits: returns x with the n bits that begin at position p set to the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n,unsigned y)
{
    return (x & ~((~(~0 << n)) << (p-n+1))) | (y & ~(~0 << n)) << (p-n+1);
}