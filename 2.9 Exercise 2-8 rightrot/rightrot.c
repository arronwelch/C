
/* 
 * Exercise 2-8. 
 * Write a function rightrot(x,n) that returns the value of the integer x 
 * rotated to the right by n positions.
 */

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n,unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

int main(void)
{
    printf("\n rightrot = 0x%2x \n",rightrot(0x6b,3));

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

/* rightrot: returns the value of the integer x rotated to the right by n positions */
unsigned rightrot(unsigned x, int n)
{
    while(n--)
    {
        x = ( (x & 0x01) << 7) | ( x >> 1) ;
    }
    return x;
}