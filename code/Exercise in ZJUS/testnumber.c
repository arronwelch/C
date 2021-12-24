
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int number = rand()%100 + 1;
    int count = 0;
    int a = 0;
    printf("number is a digit between 0 to 100.\n");
    do
    {
        printf("please input your number:");
        scanf("%d", &a);
        count++;
        if ( a > number )
            printf("your number is too big!\n");
        else if ( a < number)
            printf("your number is too small!\n");
    } while (a != number);
    printf("Great! you are right! count is only %d \n", count);

    return 0;
}