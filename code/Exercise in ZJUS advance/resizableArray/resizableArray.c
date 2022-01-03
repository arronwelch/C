
#include <stdio.h>
#include <stdlib.h>
#include "resizableArray.h"

const BLOCK_SIZE = 20;

// #ifndef _RESIZABLEARRAY_H_
// #define _RESIZABLEARRAY_H_

// typedef struct {
//     int *array;
//     int size;
// } Array;

Array array_create(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int *)malloc(sizeof(int) * a.size);

    return a;
}

void array_free(Array *a)
{
    free(a->array);
    a->size = 0;
    a->array = NULL;
}

// package
int array_size(const Array *a)
{
    return a->size;
}

int *array_at(Array *a, int index)
{
    if (index >= a->size)
    {
        // array_inflate(a,index - a->size + 1);
        array_inflate(a, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size);
    }
    return &(a->array[index]);
}

int array_get(const Array *a, int index)
{
    return a->array[index];
}

void array_set(Array *a, int index, int value)
{
    a->array[index] = value;
}

void array_inflate(Array *a, int more_size)
{
    int *p = (int *)malloc(sizeof(int) * (a->size + more_size));

    for (size_t i = 0; i < a->size; i++)
    {
        p[i] = a->array[i];
    }
    // memcpy ?
    free(a->array);
    a->array = p;
    a->size = a->size + more_size;
}

// #endif

int main(int argc, char const *argv[])
{
    Array a = array_create(100);
    printf("Array a's size is %d\n", array_size(&a));

    // *array_at(&a,0) = 10;
    // printf("*array_at(&a,0) is %d\n",*array_at(&a,0));

    array_set(&a, 0, 10);
    printf("array_get(&a,0) = %d\n", array_get(&a, 0));

    int number;
    int cnt = 0;
    while (number != -1)
    {
        scanf("%d",&number);
        if (number != -1)
        {
            *array_at(&a,cnt++) = number;
        }
        // scanf("%d", array_at(&a, cnt++));
    }

    array_free(&a);
    return 0;
}
