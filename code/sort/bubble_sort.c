#include <stdio.h>

void bubble_sort(int arr[], int len)
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
}

int main(void)
{
    int arr[] = {1, 5, 85, -5, 0, 1234, 5, 8, 9, 12};
    int len = (int)sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, len);
    int i = 0;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}