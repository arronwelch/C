
#include <stdio.h>

int main()
{
    const int ARRAY_LEN = 10;
    int x;
    int count[ARRAY_LEN];
    int i;
    for (i = 0; i < ARRAY_LEN; i++)//Init arrays
    {
        count[i] = 0;
    }
    scanf("%d", &x);
    while (x != -1)
    {
        if (x >= 0 && x <= 9)
        {
            count[x]++;
        }
        scanf("%d", &x);
    }
    for (i = 0; i < ARRAY_LEN; i++)
    {
        printf("%d:%d\n", i, count[i]);
    }

    return 0;
}