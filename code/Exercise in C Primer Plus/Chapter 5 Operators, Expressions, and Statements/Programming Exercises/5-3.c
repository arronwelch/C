/* Programming Exercises 5-3.c */

/*
3.  Write a program that asks the user to enter the number of days and then converts that
    value to weeks and days.For example, it would convert 18 days to 2 weeks, 4 days.
    Display results in the following format:
    18 days are 2 weeks, 4 days.
    Use a while loop to allow the users to repeatedlly enter day values;terminate the loop
    when the user enters a nonpositive value, such as 0 or -20.
*/

#include <stdio.h>
#define D_TO_w 7 // days per week

int main(void)
{
    int days;
    int weeks;
    int left;

    printf("This program converts days to weeks and days.\n");
    printf("Just enter the number of days.\n");
    printf("Enter 0 or less to end the program.\n");
    scanf("%d", &days);
    while (days > 0)
    {
        weeks = days / D_TO_w;
        left = days %  D_TO_w;
        printf("%d days are %d weeks, %d days.\n", days, weeks, left);
        printf("Next input?\n");
        scanf("%d", &days);
    }
    printf("Bye!\n");

    return 0;
}