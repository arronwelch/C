/*
1516000/10 151600
1516000%10 [0]
151600/10  15160
151600%10  [0]
15160/10   1516
15160%10   [0]
1516/10    151
1516%10    [6]
151/10     15
151%10     [1]
15/10      1
15%10      [5]
1/10       0
1%10       [1]
*/

#include <stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    if(x!=0)
    {
        printf("%d",x%10);
        x /= 10;
    }
    do
    {
        printf("%d",x%10);
    }
    while(x /= 10);
    printf("\n");
    return 0;
}