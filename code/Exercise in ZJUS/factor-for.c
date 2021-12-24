
#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);
    int fact = 1;
    int i = n;
    // for (int i = 1; i <= n; i++)// -stf = C99
    // {
    //     fact *= i;
    // }
    for ( ;n > 1; n--)
    {
        fact *= n;
    }

    printf("%d! = %d\n", i , fact);

    return 0;
}