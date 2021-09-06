
#include <stdio.h>

void swap(int *px, int *py);

int main(void)
{
    int x = 1, y = 2, z[10];
    int *ip;   /* ip is a pointer to int type variable[mnemonic] */

    swap(&x,&y);

    ip = &x;   /* ip now points to x */
    printf("ip = %p\n",ip);//ip = 000000000061FE0C (address，64bit)
    y = *ip;   /* y is now 1 */
    printf("y = %d\n",y);
    *ip = 0;   /* x is now 0 */
    printf("x = %d\n",x);    
    ip = &z[0]; /* ip now points to int array z's first address(z[0]) */

    z[3] = 3;
    printf("z[3] = %d\n",z[3]);
    printf("*(ip+3) = %d\n",*(ip+3));

    *ip = *ip + 10;

    y = *ip + 1;

    *ip += 1;
    
    ++*ip;

    (*ip)++;// the parentheses are necessary in this last example,
            // because unary operators like * and ++ associate right to left  [ left<--right ]
    
    int *iq;
    iq = ip;
    printf("*(iq+3) = %d\n",*(iq+3));


    return 0;
}

/* swap： interchange *px and *py 
 * int a = 0, b = 1;
 * swap(&a,&b);
 */
void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}