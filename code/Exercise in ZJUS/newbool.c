
#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool b = 6 > 5;
    printf("%d\n", b);
    
    bool t = true;
    printf("%d\n", t);
    t = -2;
    printf("%d\n", t);//[NOTE]
    t = 0;
    printf("%d\n", t);

    return 0;
}