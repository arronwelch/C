

#include <stdio.h>

int amount[] = {1, 5, 10, 25, 50};
char *name[] = {"penny", "nickel", "dime", "quarter", "half-dollar"};

struct
{
    int amount;
    char *name;
} coins[] = {
    {1, "penny"},
    {5, "nickel"},
    {10, "dime"},
    {25, "quarter"},
    {50, "half-dollar"}};

int search(int key, int a[], int len)
{
    int ret = -1;
    int i;
    for (i = 0; i < len; i++)
    {
        if (key == a[i])
        {
            ret = i;
            break;
        }
    }
    return ret;
}

int main()
{
    int k;
    // scanf("%d",&k);
    k = 10;
    // int r = search(k,amount,sizeof(amount)/sizeof(amount[0]));

    for (size_t i = 0; i < sizeof(coins) / sizeof(coins[0]); i++)
    {
        if (k == coins[i].amount)
        {
            printf("%s\n", coins[i].name);
            break;
        }
    }

    printf("\n");
    return 0;
}