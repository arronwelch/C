

/*
9876673

9876673/10 = 987667
9876673%10 = [3]

987667/10  = 98766
987667%10  = [7]

9876
[6]

9
[8]

0
[9]


*/

#include <stdio.h>

int main()
{
    int input = 0, output = 0;
    int rem = 0;
    unsigned char numflag[10] = {0};
    scanf("%d",&input);
    while( (rem = input%10) != 0)
    {
        input /= 10;
        if(numflag[rem] == 0)
        {
            output = output*10 + rem;
            numflag[rem] = 1;
        }
    }
    printf("%d\n",output);
    return 0;
}