
#include <stdio.h>

struct date
{
    int month;
    int day;
    int year;
};

// int main(int argc, char const *argv[])
int main()
{
    // struct date
    // {
    //     int month;
    //     int day;
    //     int year;
    // };
    // struct date today;

    // today.month = 1;
    // today.day = 2;
    // today.year = 2022;

    // struct date today = {1, 2, 2022};
    // struct date thismonth = {.year = 2022,.month = 1};

    struct date today;

    today = (struct date){1,2,2022};

    struct date day;

    day = today;//struct can assign as a whole!
    day.year = 2023;

    struct date *pDate = &today;

    printf("Today's date is %i-%i-%i.\n",
           today.year, today.month, today.day);

    // printf("This month is %i-%i-%i.\n",
    //        thismonth.year, thismonth.month, thismonth.day);

    printf("The day is %i-%i-%i.\n",
           day.year, day.month, day.day);

    printf("address of today is %p\n",(void *)pDate);

    return 0;
}