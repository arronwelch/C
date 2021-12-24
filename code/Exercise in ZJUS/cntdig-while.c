
#include <stdio.h>

int main()
{
    int x;
    int n = 0;
    // scanf("%d",&x);
    x = 352;
    // n++;
    // x /= 10;
    while (x > 0)
    {
        printf("in loop\n");
        n++;
        x /= 10;
        printf("x = %2d, n = %2d\n", x, n);
    }
    printf("%d\n", n);
}

// analyze:
/*
x       n
352     0
35      1
3       2
0       3

test code:
    1.boundary testing:
        [1].one digit;
        [2].10;
        [3].0;
        [4].negative.
    2.magical input/special input;
*/