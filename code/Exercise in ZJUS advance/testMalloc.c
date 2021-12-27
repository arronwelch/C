
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int number;
    // int *a;
    // int i;
    // printf("please input number:");
    // scanf("%d",&number);
    // // int a[number];//c99 only

    // a = (int *)malloc(number*sizeof(int));
    // for (size_t i = 0; i < number; i++)
    // {
    //     scanf("%d",&a[i]);
    // }

    // for( i = number -1; i>= 0; i--)
    // {
    //     printf("%d ",a[i]);
    // }
    // free(a);

    void *p;
    int cnt = 0;
    while ( (p = malloc(100*1024*1024)))
    {
        cnt++;
    }
    printf("allocate %d00MB memory\n",cnt);

    return 0;
}