#include <stdio.h>
#include <stdlib.h> //EXIT_SUCCESS
/*
<<5.5
>>6
<<2.499
>>2
*/

int main()
{
    float x;
    while(scanf("%f",&x) == 1)
    {
        printf("%d\n",(int)(x+0.5));
    }
    return EXIT_SUCCESS;
}