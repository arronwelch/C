/*
3
2
2
1
11
10
20
40
32
67
40
20
89
300
400
15
*/

#include <stdio.h>

void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(int v[],int left,int right)
{
    int i, last;

    if (left >= right)
        return;
   swap(v,left,(left+right)/2);
   last = left;
   for(i = left+1;i <= right; i++)
       if (v[i] < v[left])
           swap(v,++last,i);
   swap(v,left,last);
   qsort(v,left,last-1);
   qsort(v,last+1,right);
}

int main()
{
    int i = 0;
    int n = 0;
    int val[1000] = {0};

    while(scanf("%d",&n) != EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&val[i]);
            for(int j=0;j<i;j++)
                if(val[i] == val[j])
                {
                    val[i] = 0;
                    n--;
                    i--;
                }
        }
        qsort(val,0,n-1);
        for(int k=0;k<n;k++)
            printf("%d\n",val[k]);
    }

    return 0;
}