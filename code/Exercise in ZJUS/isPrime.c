
#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);

    int i;
    int isPrime = 1; // x is Prime ?

    for (i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            isPrime = 0;
            break;
        }
    }

    if (1 == isPrime)
    {
        printf("%d is Prime\n", x);
    }
    else
    {
        printf("%d isn't Prime\n", x);
    }

    return 0;
}