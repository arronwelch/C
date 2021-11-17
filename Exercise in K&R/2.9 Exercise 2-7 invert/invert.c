
/* 
 * Exercise 2-7. 
 * Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
 */

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n,unsigned y);
unsigned invert(unsigned x, int p, int n);

int main(void)
{
    printf("\n invert = 0x%2x \n",invert(0x6b,4,3));

    return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* setbits: returns x with the n bits that begin at position p set to the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n,unsigned y)
{
    return (x & ~((~(~0 << n)) << (p-n+1))) | (y & ~(~0 << n)) << (p-n+1);
}

/* invert: returns x with the n bits that begin at position p inverted */
unsigned invert(unsigned x, int p, int n)
{
    return  setbits( x ,p ,n ,~getbits(x,p,n));
}