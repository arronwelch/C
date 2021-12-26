
#include <stdio.h>

/**
 find key local in array a
 @param key the number need find
 @param a the array need find
 @param length the length of array
 @return if find, return it local in array a,else return -1.
 */
int search(int key, int a[], int length);

int main()
{
    // int a[] = {2, 4, 6, 7, 1, 3, 5, 9, 11, 13, 23, 14, 32};
    // int a[] = {2};
    // int a[13] = {2};
    // int a[13] = {0};//initial all 0;
    // int a[13] = {
        // [1] = 2,4,[5] = 6
    // };
    int a[ ] = {
        [1] = 2,4,[5] = 6
    };

    {
        int i;
        printf("%lu\n",sizeof(a));
        printf("%lu\n",sizeof(a[0]));
        for ( i = 0; i < 13; i++)
        {
            printf("%d\t",a[i]);
        }
        printf("\n");
    }

    int x;
    int loc;
    printf("please input a number:");
    scanf("%d", &x);
    loc = search(x, a, sizeof(a) / sizeof(a[0]));//use sizeof auto-calc array length,unit is byte
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

int search(int key, int a[], int length)//length is must in array
{
    int ret = -1;
    int i;
    for (i = 0; i < length; i++)
    {
        if (key == a[i])
        {
            ret = i;
            break;
        }
    }

    return ret;
}