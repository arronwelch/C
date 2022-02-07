#include <stdio.h>

#define MAX 60

/*
dynamic programming (0-1 knapsack problem)

condition:
item number 1 2 3 4
item volume 2 3 4 5
item value  3 4 5 6
------------------------------------------
line:the last N item(0 1 2 ... N)
column: the max volume
------------------------------------------
    0 1 2 3 4 5 6 7 8
  0 0 0 0 0 0 0 0 0 0
  1 0
  2 0
  3 0
  4 0

*/

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