
#include <stdio.h>

int main()
{
    int x = 0;
    int mask = 1;
    int t = 0;
    scanf("%d", &x);
    t = x;
    while (t > 9)
    {
        mask *= 10;
        t /= 10;
    }
    printf("x = %d,t = %d, mask = %d\n", x, t, mask);

    do
    {
        int d = x / mask;
        printf("%d", d);
        if (mask > 9)
        {
            printf(" ");
        }
        x %= mask;
        mask /= 10;
    } while (mask > 0);
    printf("\n");

    return 0;
}