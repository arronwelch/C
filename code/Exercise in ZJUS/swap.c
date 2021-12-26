
#include <stdio.h>

void swap(int x, int y);

int main()
{
    int a = 5;
    int b = 6;
    swap(a, b);

    printf("a = %d, b = %d\n", a, b);//Can swap finish?

    return 0;
}

void swap(int x, int y)
{
    int i;//local variable
    printf(" i = %d\n",i);
    printf(" x = %d\n",x);
    int t = x;
    x = y;
    y = t;
}
