#include <stdio.h>

// log2(n)
int binSearch(int key, int a[], int len)
{
    int ret = -1;
    int left = 0;
    int right = len - 1;
    while (right > left)
    {
        int mid = (left + right) / 2;
        if (a[mid] == key)
        {
            ret = mid;
            break;
        }
        else if (a[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ret;
}

int main()
{
    int a[] = {2, 4, 6, 7, 1, 3, 5, 9, 11, 13, 23, 14, 32};

    int x;
    int loc;
    printf("please input a number:");
    scanf("%d", &x);

    loc = binSearch(x, a, sizeof(a) / sizeof(a[0]));

    if (loc != -1)
    {
        printf("%d in location %d\n", x, loc);
    }
    else
    {
        printf("%d not existence\n", x);
    }

    return 0;
}