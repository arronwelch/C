#include <stdio.h>

int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    if(n%2)
        cnt++;
    n/=2;
    do
    {
        if(n%2)
            cnt++;
    }
    while(n/=2);
    printf("%d\n",cnt);
    return 0;
}