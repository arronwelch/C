#include <stdio.h>

#define MAX 60

int main()
{
    int N,m;
    scanf("%d %d",&N,&m);
    int v[MAX],w[MAX],q[MAX],sum[MAX];
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&v[i],&w[i],&q[i]);
    }
    return 0;
}