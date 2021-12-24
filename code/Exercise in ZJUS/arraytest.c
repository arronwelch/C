
#include <stdio.h>

int f();

int main()
{
    int p = 0;
    p = f();
    printf("run here! %d\n",p);

    return 0;
}

int f()
{
    int a[10];
    for (size_t i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    // a[10] = 1; // error test
    return a[9];
}