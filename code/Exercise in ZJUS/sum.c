
#include <stdio.h>

//a function prototype:
void sum(int begin, int end);//function declaration

int main()
{
    sum(1, 10);// int sum(int,int); implicit declaration of function
    sum(20, 30);
    sum(35, 45);

    return 0;
}

void sum(int begin, int end)//function definition
{
    int i;
    int sum = 0;
    for (i = begin; i <= end; i++)
    {
        sum += i;
    }
    printf("sum of %d to %d is %d\n", begin, end, sum);
}