
#include <stdio.h>

void cheer(int i)
{
    printf("cheer %d\n",i);
}

int main()
{
    cheer(2.4);//double to int!!!

    return 0;
}