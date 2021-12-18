
#include <stdio.h>

void shellsort(int v[], int n);

int main(void)
{
    int v[5] = {2,5,3,1,4};
    for(int i = 0;i<5;i++)
        printf("%d ",v[i]);
    printf("\n");
    shellsort(v,5);
    for(int i = 0;i<5;i++)
        printf("%d ",v[i]);

    return 0;
}


/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) 
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}