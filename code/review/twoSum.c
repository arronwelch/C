#include <stdio.h>
#include <stdlib.h>

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int* twoSum(int* nums, int numsSize, int target, int* returnSize){
//     int i,j;
//     int *ret = (int*) malloc(2*sizeof(int));
//     for(i=0; i < numsSize-1;i++)
//     {
//         for(j = i+1;j < numsSize; j++)
//         {
//             if( *(nums+i) + *(nums+j) == target)
//             {
//                 *ret = i;
//                 *(ret+1) = j;
//                 *returnSize =2;
//                 goto flag;
//             }
//         }
//     }
//     flag:return ret;
// }

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (*(nums + i) + *(nums + j) == target)
            {
                int *ret = (int *)malloc(2 * sizeof(int));
                *ret = i;
                *(ret + 1) = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main(void)
{
    int nums[] = {2, 7, 11, 15};
    int retSize;
    int *ret = twoSum(nums, 4, 9, &retSize);
    // for(int i=0; i<retSize; i++)

    printf("[%d,%d]\n", *ret, *(ret + 1));

    return 0;
}