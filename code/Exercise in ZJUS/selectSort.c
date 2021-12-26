
#include <stdio.h>

#undef max
int max(int a[], int len)
{
    int maxid = 0;
    for (int i = 1; i < len; i++)
    {
        if (a[i] > a[maxid])
        {
            maxid = i;
        }
    }
    return maxid;
}

int fun(int x)
{
    return (x < 3 ? 1 : (fun(x - 1) + 2 * fun(x - 2)));
}

int main()
{
    int a[] = {2, 45, 6, 12, 87, 34, 90, 24, 23, 11, 65};
    int len = sizeof(a) / sizeof(a[0]);

    for (int i = len - 1; i > 0; i--)
    {
        int maxid = max(a, i + 1);
        // swap a[maxid],a[len-1]
        int t = a[maxid];
        a[maxid] = a[i];
        a[i] = t;
    }

    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    char ch = 'A';
    ch += 32;
    printf("%d %c\n", 'B' + '8' - '3', 71);

    printf("%d\n", fun(4) + fun(5));

    int number, right_digit;
    number = 15292;
    if (number == 0)
    {
        printf("0");
    }
    else
        while (number != 0)
        {
            right_digit = number % 10;
            printf("%i\n", right_digit);
            number /= 10;
        }


    {
        int x = 0;
        int y =4;
        printf("%d,%d\n",-10<x & y<0,-17%4);
    }
    return 0;
}