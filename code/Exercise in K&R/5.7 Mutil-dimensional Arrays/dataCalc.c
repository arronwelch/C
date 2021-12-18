
/**
 * Exercise 5-8:
 * There is no error checking in day_of_year or month_day.Remedy this defect.
*/

#include <stdio.h>

/* functions declaration */
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday,int *pmonth, int *pday);

int main(void)
{
    int dayofyear,month,day;
    dayofyear = day_of_year(2021,9,12);
    
    month_day(2021,dayofyear,&month,&day);
    if (dayofyear > 0)
        printf("2021\\%d\\%d:this is the %d day of 2021\n",month,day,dayofyear);    
}

/* this is two dimensional array */
static char daytab[2][13] = //made it char to illustrate a legitimate use of char for storing small non-character integers.
{
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

/* functions definition: need use storage */

/* day of year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (year <=0 )
    {
        printf("ERROR:year %d\n",year);
        return -1;
    }
        
    if (month < 1 || month > 12)
    {
        printf("ERROR:month %d\n",month);
        return -2;
    }
    
    leap = year%4 == 0 && year%100 != 0 || year%400 ==0;

    if (day < 1 || day > daytab[leap][month])
    {
        printf("ERROR:day %d\n",day);
        return -3;
    }

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday,int *pmonth, int *pday)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (yearday < 1 || yearday > 365+leap)
    {
        printf("ERROR:yearday %d\n",yearday);
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}