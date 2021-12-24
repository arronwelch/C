
#include <stdio.h>

int main()
{
    int x;
    // scanf("%d", &x);
    int cnt = 0;

    x = 2;

    // for (x = 2; x < 100; x++)
    // while( cnt < 50)
    for (x = 2; cnt < 50; x++)
    {
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
            printf("%d ", x);
            cnt++;
        }
        // x++;
    }
    printf("\n");

    return 0;
}