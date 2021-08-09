#include <stdio.h>
// int power(int m, int n);
// int power(int , int );//formal parameter names are optional
int power();/* (old-style version) */
int powerf(int base, int n);
/* test power function */
int main()
{
    int i;
    for (i = 0; i < 10; ++i)
        printf("%d %d %d %d\n", i, power(2, i), power(-3, i), powerf(-3, i));
    return 0;
}
// /* power: raise base to n-th power; n >= 0 */
// int power(int base, int n)
// {
//     int i, p;
//     p = 1;
//     for (i = 1; i <= n; ++i)
//         p = p * base;
//     return p;
// }

/* power: raise base to n-th power; n >= 0 */
/* (old-style version) */
int power(base,n)
int base, n;
{
    int i, p;
    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

/* power: raise base to n-th power; n >= 0; version 2 */
int powerf(int base, int n)
{
int p;
for (p = 1; n > 0; --n)
p = p * base;
return p;
}