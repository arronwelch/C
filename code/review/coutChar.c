
/*
ABCabc
A
2
*/

#include <stdio.h>
#include <string.h>

str[1000];

int main()
{
    int c=0;
    int i=0;
    int cnt=0;

    while((c=getchar())!='\n')
    {
        str[i++] = c;
    }
    str[i++] = '\n';

    c = getchar();
    for(int j=0;j<i;j++)
    {
        if(tolower(str[j]) == tolower(c))
            cnt++;
    }
    printf("%d\n",cnt);

    return 0;
}