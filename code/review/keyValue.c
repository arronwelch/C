#include <stdio.h>

#define N (11111111+1) 
// 1 <= n <= 500
// 0 <= key <= 11111111
// 1 <= value <= 100000

long int key[N] = {0};
long int value[N] = {0};

int main()
{
    int n=0;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        long int a,b;
        scanf("%ld %ld",&a,&b);
        key[a] = 1;
        value[a] += b;
    }
    for(int i=0;i<N;i++)
    {
        if(key[i] == 1)
            printf("%d %ld\n",i,value[i]);
    }
    return 0;
}