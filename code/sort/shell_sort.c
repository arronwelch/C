#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shell_sort(int arr[],int len)
{
    int i,j;
    for(i = 0; i < len -1; i++)
    {
        int min = i;
        for(j = i+1; j < len;j++)
        {
            if ( arr[j] < arr[min])
                min = j;
        }
        swap( &arr[min], &arr[i]);
    }
}

int main(void)
{
    int arr[] = {1, 5, 85, -5, 0, 1234, 5, 8, 9, 12};
    int len = (int)sizeof(arr) / sizeof(*arr);
    shell_sort(arr, len);
    int i = 0;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}