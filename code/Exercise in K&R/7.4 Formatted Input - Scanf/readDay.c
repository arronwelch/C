
#include <stdio.h>

int main(void)
{
    int day, year;
    char monthname[20];
    scanf("%d %s %d",&day,monthname,&year);
    //No & is used with monthname, since an array name is a pointer.

    printf("%d %s %d\n",day,monthname,year);    

    return 0;
}