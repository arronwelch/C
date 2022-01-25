
/*
hello nowcoder
8
*/

#include <stdio.h>
 
int main()
{
    int c=0;
    int n=0;
    int cnt=0;
    while((c=getchar())!='\n'&& n < 5000)
    {
        n++;
        cnt++;
        if(c == ' ')
            cnt = 0;
    }
    printf("%d\n",cnt);
 
    return 0;
}