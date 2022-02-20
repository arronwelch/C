#include <stdio.h>

void insertion_sort(int arr[], int len)
{
    int i, j, temp;
    for (i = 1; i < len; i++)
    {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

int main(void)
{
    int arr[] = {1, 5, 85, -5, 0, 1234, 5, 8, 9, 12};
    int len = (int)sizeof(arr) / sizeof(*arr);
    insertion_sort(arr, len);
    int i = 0;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}