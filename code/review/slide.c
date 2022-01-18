
/*

 1 0 0 ... 0
 ^
 1 2 0 ... 0
   ^
 1 2 3 ... 0
     ^
...
 1 2 3 ... 15
            ^
 16 2 3 ... 15
  ^
 16 17 3 ... 15
    ^
*/

#include <stdio.h>

float Slide(int x);

#define N 16

int SlideArray[N] = {0};//initialize 0

float Slide(int x)
{
    static int sum=0;
    static int new_index=0;

    sum -= SlideArray[new_index];
    SlideArray[new_index] = x;
    sum += SlideArray[new_index];
    new_index++;
    if(N == new_index)
    {
        new_index = 0;
    }

    return (sum*1.0)/N;
}

int main()
{
    for(int i = 0 ; i < 16; i++)
    {
        printf("x = %f\n",Slide(16));
    }

    return 0;
}