#include <stdio.h>
#define MAX 128

int main()
{
    int x,flag[MAX] = {0};
    int cnt = 0;
    while((x=getchar()) != '\n' && x != EOF)
    {
        if(flag[x] == 0)
            flag[x] = 1;
    }
    printf("%d\n",cnt);
    return 0;
}
