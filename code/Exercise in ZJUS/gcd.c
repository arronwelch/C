
/*
step1. if b equal to 0,loop exit; a is gcd;
step2. else calc t = a % b , a = b, b = t.
step3. rebcak step1


a   b   t
12  18  12
18  12  6
12  6   0
6   0
*/

#include <stdio.h>

int main()
{
    int a,b;
    int t;
    scanf("%d %d",&a, &b);
    while ( b!= 0)
    {
        t = a%b;
        a = b;
        b = t;
        printf("a=%2d,b=%2d,t=%2d\n",a,b,t);
    }
    printf("gcd = %d\n",a);

    return 0;
}