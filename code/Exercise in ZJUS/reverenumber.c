
#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);

    int digit;
    int ret = 0;

    while (x > 0)
    {
        digit = x % 10;
        printf("%d", digit);
        ret = ret * 10 + digit;
        // printf( "x = %d, ret = %d, digit = %d\n",x,ret,digit);
        x /= 10;
    }
    // printf("\nret = %d\n",ret);
    printf("\n");

    return 0;
}