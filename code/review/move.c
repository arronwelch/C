#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 10000

int main()
{
    int str[MAX_LEN],x=0,y=0;
    while ( (str[0]=getchar()) != EOF)
    {
        if(str[0] == ';')
            continue;
        if(str[0] == 'W')// up move
        {
            if(isdigit(str[1] = getchar()))
                if(isdigit(str[2] = getchar()))
        }
        else if(str[0] == 'S')// down move
            y--;
        else if(str[0] == 'A')// left move
        {
            x--;
        }
        else if(str[0] == 'A')// right move
        {

        }
    }

    return 0;
}
